#include "ToDoList.h"

namespace list_ns
{

	

	void ToDoList::loadData()
	{
		std::ifstream file;
		file.open(filename);

		if (!file.is_open()) return;


		long long triggerEpochSecs;
		std::string message;
		char delim;
		std::string line;
		char period;
		std::stringstream ss;
		while (!file.eof()) {

			std::getline(file, line);

			if (!line.empty()) {
				ss.str("");
				ss << line.c_str();
				ss >> period;
				
				ss >> triggerEpochSecs;
				ss >> delim;
				std::getline(ss, message);
				
				std::chrono::system_clock::time_point point{ std::chrono::seconds{ triggerEpochSecs } };
				if (period == 'n')
				{
					ToDoItem * newItem = new ToDoItem(point, message);
					addItem(newItem);
					continue;
				}

				ToDoItem * newItem = new ToDoPeriodicItem(point, message, period);
				addItem(newItem);
			}


		}
	}
	

	void ToDoList::saveData()
	{
		std::ofstream file;
		file.open(filename, std::ios::trunc);

		if (file.is_open()) {

			for (int i = 0; i < items_amount; i++)
			{
				file << *pList[i];
			}
		}
	}


	int compare(const void * item1, const void * item2)
	{
		return (static_cast<const ToDoItem*>(item1)->getTimePoint() - static_cast<const ToDoItem*>(item2)->getTimePoint()).count();
	}

	ToDoItem& ToDoList::getFront()
	{
		return **pList;
	}
	ToDoItem& ToDoList::getBack()
	{
		return **(pList + items_amount - 1);
	}

	void ToDoList::pop()
	{
		
		if (pList && items_amount > 0)
		{
			delete pList[items_amount - 1]; 
			items_amount--;
		}
		

		
	}

	void ToDoList::notificationWork()
	{
		while (this->isWorking)
		{
			
			if (pList && items_amount > 0)
			{
				std::lock_guard<std::mutex> guard(mx);
				auto tp = this->getBack().getTimePoint();
					if (tp <= std::chrono::system_clock::now())
					{
						this->callback(this->getBack());
						if (this->getBack().isPeriodic())
						{
							this->getBack().appendTimepoint();
							qsort(pList, items_amount, sizeof(ToDoItem*), &compare);
						}
						else
						{
							pop();
						}

						
					}
					

				}
			}
			
		 std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	

	void ToDoList::resize()
	{
		capacity <<= 1;
		ToDoItem ** temp = pList;
		pList = new ToDoItem*[capacity];
		if (temp)
		{
			for (int i = 0; i < items_amount; i++)
			{
				pList[i] = temp[i];
			}
			delete[] temp;
		}
		
	}
	
	void ToDoList::setCallbackNotifier(std::function<void(ToDoItem &)> callback)
	{
		std::lock_guard<std::mutex> lock(mx);
		this->callback = std::move(callback);
	}

	void ToDoList::addItem(ToDoItem *& p_item)
	{
		std::lock_guard<std::mutex> lock(mx);
		if (pList)
		{
			if (isFull())
			{
				resize();
			}
		}
		else
		{
			capacity = 1;
			resize();
		}
		*(pList + items_amount++) = p_item;
		std::qsort(pList, items_amount, sizeof(ToDoItem*), compare);

	}


	void ToDoList::detachCallBack()
	{
		this->callback = nullptr;
	}

	ToDoList::~ToDoList()
	{

		this->isWorking = false;
		if (thread.joinable())
		{
			thread.join();
		}
	
		saveData();
		if (pList)
		{
			for (int i = 0; i < this->items_amount; i++)
			{
				delete pList[i];
			}
			delete[] pList;
			pList = NULL;
		}
		detachCallBack();


	}
	ToDoList::ToDoList() : pList{ NULL }, items_amount{ 0 }, capacity{0}, isWorking{ true }
	{
		loadData();
		thread = std::thread(&ToDoList::notificationWork, this);

	}
	bool ToDoList::isFull()
	{
		return items_amount >= capacity;
	}
}