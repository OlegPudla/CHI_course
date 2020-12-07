#include "ToDoPeriodicItem.h"


namespace list_ns
{
	void ToDoPeriodicItem::appendTimepoint()
	{
		
		int hours_24 = period_pair.second >= DAY ? 24 : 1;
		int days_7 = period_pair.second >= WEEK ? 7 : 1;
		int weeks_4 = period_pair.second == MONTH ? 4 : 1;
	

		this->timePoint += (std::chrono::hours(1) * hours_24 * days_7 * weeks_4) + std::chrono::hours(48) * (period_pair.second == MONTH);
		
	}
	ToDoPeriodicItem::ToDoPeriodicItem(time_point_type TimePoint, std::string message, char  period) : ToDoItem(TimePoint, message, true)
	{

		switch (period)
		{
		case('h'): {period_pair.first = 'h', period_pair.second = HOUR; break; }
		case('d'): {period_pair.first = 'd', period_pair.second = DAY; break; }
		case('w'): {period_pair.first = 'w', period_pair.second = WEEK; break; }
		case('M'): {period_pair.first = 'M', period_pair.second = MONTH; break; }
		default: {period_pair.first = 'h', period_pair.second = HOUR; break; }
		}
	}
	std::ostream & ToDoPeriodicItem::print(std::ostream & os)
	{
		
		os << this->period_pair.first << ' '
			<< std::chrono::duration_cast<std::chrono::seconds>(this->getTimePoint().time_since_epoch()).count()
			<< '-' << this->getMessage()
			<< std::endl;
		return os;
	}

}
