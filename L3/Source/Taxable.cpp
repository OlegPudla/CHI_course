#include "Taxable.h"

namespace sict
{

	void TaxableProduct::display(std::ostream & os) const
	{
		os << std::setw(FW) << this->product_number << std::setw(FW) << /*std::setprecision(2) <<*/ this->price() << std::setw(FW) << tax_pair.first  << '\n';
	}
	double TaxableProduct::price() const
	{
		return this->product_price* (1.0 + tax_pair.second);
	}

	TaxableProduct::TaxableProduct(int product_number, double product_price, char  product_tax) : Product(product_number, product_price)
	{
		
		if (product_tax == 'H')
		{
			tax_pair.first = "HST";
			tax_pair.second = 0.13;
		}
		else
		{
			tax_pair.first = "PST";
			tax_pair.second = 0.08;
		}
	
	}
}