#include <iostream>
#include <string>
#include <exception>

#include "input_reader.h"
#include "group.h"

using namespace std::literals;

void Menu(ManagerGroup& mg) {
	std::cout << "\033[2J\033[1;1H";
	int option = 0;
	std::string name_file;
	std::cout << "Specify a new file(1)\n"sv
		<< "Save group by distance(2)\n"sv
		<< "Save Group by Name(3)\n"sv
		<< "Save group by Type(4)\n"sv
		<< "Save Group by Date(5)\n"sv
		<< "Save all objects to another file(6)\n"sv 
		<< "Enter to escape(7)\n"sv
		<< "---------------------------------------\n"sv;
	std::cin >> option;
	std::cin.get();
	switch (option) {
	case 1: {
		std::cout << "Input file: "sv;
		std::getline(std::cin, name_file);
		Load(name_file, mg);
		break;
	}
	case 2: {
		std::cout << "Input file to output: "sv;
		std::getline(std::cin, name_file);
		SaveToFile(name_file, mg, "По расстоянию", SortingCriteria::Distance);
		break;
	}
	case 3: {
		std::cout << "Input file to output: "sv;
		std::getline(std::cin, name_file);
		SaveToFile(name_file, mg, "По имени", SortingCriteria::Name);
		break;
	}
	case 4: {
		std::cout << "Input file to output: "sv;
		std::getline(std::cin, name_file);
		SaveToFile(name_file, mg, "По типу", SortingCriteria::Type);
		break;
	}
	case 5: {
		std::cout << "Input file to output: "sv;
		std::getline(std::cin, name_file);
		SaveToFile(name_file, mg, "По дате", SortingCriteria::Date);
		break;
	}
	case 6: {
		std::cout << "Input file to output: "sv;
		std::getline(std::cin, name_file);
		PrintToFile(name_file, mg);
		break;
	}
	case 7:
		return;
	}
	Menu(mg);
}

int main()
{
	std::setlocale(LC_COLLATE, "ru_RU.UTF-8");
	
	ManagerGroup mg;

	try {
		Menu(mg);
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
		Menu(mg);
	}

	return 0;
}
