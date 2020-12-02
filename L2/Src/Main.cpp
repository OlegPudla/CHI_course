
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Pair.h"
#include "List.h"


int main(int argc, char** argv) {


	
	bool keepreading;

	std::ofstream ofs("lab3output.txt");

	std::cout << std::fixed << std::setprecision(2);

	std::cout << "\ninventory\n=========\n";
	list <pair<std::string, double>, 5> inventory;

	std::string str;
	double price;

	keepreading = true;
	do {
		std::cout << "product : ";
		getline(std::cin, str);
		if (str.compare("quit") == 0) {
			keepreading = false;
		}
		else {
			std::cout << "price : ";
			std::cin >> price;
			std::cin.ignore();
			pair <std::string, double> pair(str, price);
			inventory += pair;
		}
	} while (keepreading);

	ofs << "\nprice list\n-----------\n";
	for (size_t i = 0; i < inventory.size(); i++)
		ofs << inventory[i].getkey()
		<< " : " << inventory[i].getvalue() << std::endl;

	std::cout << "\nglossary\n========\n";
	list <pair<std::string, std::string>, 5> glossary;
	std::string key, definition;

	keepreading = true;
	do {
		std::cout << "key : ";
		getline(std::cin, key);
		if (key.compare("quit") == 0) {
			keepreading = false;
		}
		else {
			std::cout << "definition : ";
			getline(std::cin, definition);
			pair <std::string, std::string> pair(key, definition);
			glossary += pair;
		}
	} while (keepreading);

	ofs << "\nentries\n-------\n";
	for (size_t i = 0; i < glossary.size(); i++)
		ofs << glossary[i].getkey()
		<< " : " << glossary[i].getvalue() << std::endl;

	ofs.close();
}