#pragma once
#include "ToDoItem.h"



namespace list_ns
{

enum period_type
{
	HOUR,
	DAY,
	WEEK,
	MONTH
};

	class ToDoPeriodicItem : public ToDoItem
	{
		
	private:
		std::pair<char, period_type> period_pair;
		std::ostream & print(std::ostream & os) override;
	public:
		ToDoPeriodicItem(time_point_type TimePoint, std::string message, char period);
		void appendTimepoint() override;


		
	

	};
}