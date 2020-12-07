#pragma once
#ifndef TO_DO_LIST
#define TO_DO_LIST


#include <functional>
#include <mutex>
#include <future>
#include <sstream>
#include <fstream>
#include "ToDoPeriodicItem.h"
#include "ToDoItem.h"
namespace list_ns
{
	
	class ToDoList
	{


	private:
		std::string filename = "Data.dat";
		
		std::function<void(ToDoItem &)> callback;
		std::thread thread;
		ToDoItem ** pList;
		unsigned int items_amount;
		unsigned int capacity;
		bool isWorking;
	private:

		void notificationWork();
		void resize();
		bool isFull();
		void setCallbackNotifier(std::function<void(ToDoItem &)> callback);
		void detachCallBack();
		void pop();
		void loadData();
		void saveData();
		std::mutex mx;
	public:
		
		void addItem(ToDoItem *& p_item);
		ToDoList();
		~ToDoList();
		ToDoItem& getFront();
		ToDoItem& getBack();
		

		struct NotifierGuard {
			ToDoList & list;
			
			NotifierGuard(ToDoList& list_, std::function<void(ToDoItem &)> callback)
				: list{ list_ } {
				list.setCallbackNotifier(callback);
			}
			~NotifierGuard() {
				list.detachCallBack();
			}
		};

		
	} ;
		

}






#endif // TO_DO_LIST