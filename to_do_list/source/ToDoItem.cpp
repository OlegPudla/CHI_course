#include "ToDoItem.h"
namespace list_ns
{
	ToDoItem::ToDoItem(time_point_type timePoint, std::string message, bool isPeriodic)
	{
		this->timePoint = timePoint;
		this->message = message;
		this->Periodic = isPeriodic;
	}
	const ToDoItem::time_point_type  & ToDoItem::getTimePoint() const 
	{
		return timePoint;
	}
	const std::string & ToDoItem::getMessage() const
	{
		return message;
	}
	std::ostream & ToDoItem::print(std::ostream & os)
	{

		os  <<  'n' << ' '
			<< std::chrono::duration_cast<std::chrono::seconds>(this->getTimePoint().time_since_epoch()).count()
			<< '-' << this->getMessage()
			<< std::endl;
		return os;

	}

}