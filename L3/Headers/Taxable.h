#pragma once
#include "Product.h"
namespace sict
{
	class TaxableProduct : public Product
	{
	private:
		std::pair<std::string, double> tax_pair;
	public:
		TaxableProduct(int product_number, double product_price, char tax);
		double price() const override;
		void display(std::ostream & os) const override;

	};

}