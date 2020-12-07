#pragma once
#ifndef TO_DO_ITEM
#define TO_DO_ITEM
#include <chrono>
#include <string>



namespace list_ns
{



	class ToDoItem
	{
	private:
		virtual std::ostream & print(std::ostream & os);
	protected:
		using time_point_type = std::chrono::time_point < std::chrono::system_clock>;
		time_point_type timePoint;
		std::string message;
		bool Periodic;
	public:
		
		
		virtual void appendTimepoint() {};
		
		ToDoItem(time_point_type timePoint, std::string message, bool isPeriodic = false);
		const bool isPeriodic()const { return Periodic; }
		const time_point_type & getTimePoint() const;
		const std::string & getMessage() const;
		
		friend std::ostream &operator<<(std::ostream &os, ToDoItem &item) {
			
			item.print(os);
			return os;
		}
	};


}






#endif // TO_DO_ITEM