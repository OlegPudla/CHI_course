#include "Sale.h"



namespace sict
{
	Sale::Sale(const  char * filename)
	{
		file.open(filename);
		if (!file.is_open())
		{
			throw std::string("Couldn't open file\n");
		}
		else
		{
			while (!file.eof())
			{
				iProduct * new_product = readRecord(file);
				if(new_product) products.push_back(new_product);
				
			}
		}
		
	}
	Sale::~Sale()
	{
		for (auto it = products.begin(); it != products.end(); it++)
		{
			if (*it) delete *it;
		}
		file.close();
	}
	void Sale::display(std::ostream & os)const
	{
		double total_price = 0.0;
		for (auto it = products.begin(); it != products.end(); it++)
		{
			if (*it)
			{
				std::cout << **it;
				total_price += (*it)->price();
			}
			
		}
		std::cout << std::setw(FW) << "Total price:" << std::setw(FW) <</* std::setprecision(2) <<*/ total_price << '\n';
	}
}