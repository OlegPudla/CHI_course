#pragma once
#include "Product.h"
#include "Taxable.h"
#include <iostream>

#include <vector>


namespace sict
{
	class Sale
	{
	private:
		std::vector<iProduct *> products;
		std::ifstream file;
	public:
		Sale(const char * filename);
		~Sale();
		void display(std::ostream & os)const;

	};
}