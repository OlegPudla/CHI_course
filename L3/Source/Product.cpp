#include "Product.h"
#include "Taxable.h"

namespace sict
{

	iProduct * readRecord(std::ifstream & file)
	{
		
		int product_number = 0;
		double product_price = 0.0;
		char product_tax = ' ';

		std::string info_string;
		std::stringstream ss;
		std::getline(file, info_string);
		ss.str(info_string);
		ss >> product_number;
		ss >> product_price;
		if (!ss.eof())
		{
			ss >> product_tax;
		}
		
		if (!info_string.empty())
		{
			if (toupper(product_tax) == 'H' || toupper(product_tax) == 'P')
			{
				return new TaxableProduct(product_number, product_price, product_tax);
			}
			return new Product(product_number, product_price);
		}
		return NULL;
	
		
		
	}

	std::ostream & operator << (std::ostream & os, const iProduct & p)
	{
		p.display(os);
		return os;
	}
	Product::Product(int product_number, double product_price) : iProduct()
	{
		this->product_price = product_price;
		this->product_number = product_number;
		
	}
	Product::~Product()
	{
		this->product_price = 0;
		this->product_number = 0;
	}
	double Product::price() const
	{
		return this->product_price;
	}
	void Product::display(std::ostream & os) const
	{
		os << std::setw(FW) << this->product_number << std::setw(FW) <</* std::setprecision(2) <<*/ this->price() << '\n';
	}


	
}