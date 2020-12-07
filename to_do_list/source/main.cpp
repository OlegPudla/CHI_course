#include <stdio.h>
#include <chrono>
#include <thread>
#include <functional>
#include <iostream>
#include "ToDoList.h"
#include "ToDoPeriodicItem.h"
using namespace list_ns;
int main()
{
    bool notified = false;
	std::function<void(const ToDoItem &)> testNotification =
		[&notified](const ToDoItem & item) mutable
	{ notified = true;  
	time_t time = std::chrono::system_clock::to_time_t(item.getTimePoint());
	tm local_time = *localtime(&time);

	std::cout << local_time.tm_year + 1900 << ' ' << local_time.tm_mon + 1 << ' ' << local_time.tm_mday << '\n' ;
	std::cout << item.getMessage() << std::endl; };
        
    ToDoList list;
    ToDoList::NotifierGuard guard{ list, testNotification };
	ToDoItem * item = new ToDoPeriodicItem(std::chrono::system_clock::now() + std::chrono::seconds{ 5 }, std::string("test"), 'h');
	ToDoItem * item2 = new ToDoItem(std::chrono::system_clock::now() + std::chrono::minutes{ 5 }
	, "test message");
    list.addItem(item);
	list.addItem(item2);
	

		if (notified) {
			std::cout << "Failed. Notification has come too early";
		}
		std::this_thread::sleep_for(std::chrono::seconds{ 10 });
		if (!notified) {
			std::cout << "Failed. Notification hasn't come at all";
		}
	
	

	
	
    return 0;
}