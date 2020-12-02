#pragma once
#include <ostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
extern int FW;
namespace sict
{
	
	
	class iProduct
	{
		
	public:
		virtual ~iProduct() = 0 {};
	protected:
		iProduct() {};
		
		virtual double price() const = 0;
		virtual void display(std::ostream & os) const = 0;
		friend std::ostream & operator << (std::ostream & os, const iProduct & p);
		friend class Sale;
		
		
	};


	class Product :public iProduct
	{
	protected:
		int product_number;
		double product_price;
	public:
		Product(int product_number, double product_price);
		virtual  ~Product();
		double price() const;
		void display(std::ostream & os) const;
	};

	iProduct * readRecord(std::ifstream & file);
	std::ostream & operator << (std::ostream & os, const iProduct & p);
}