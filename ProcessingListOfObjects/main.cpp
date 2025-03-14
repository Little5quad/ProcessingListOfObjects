#include <iostream>
#include <string>

#include "input_reader.h"
#include "group.h"

using namespace std::literals;

int main()
{
	std::cout << "Hello CMake." << std::endl;

	//Устраняет проблему с ру буквами в VS
	//std::setlocale(LC_ALL, "ru_RU.UTF-8");
	//setlocale(LC_ALL, "Russian");
	//SetConsoleOutputCP(1251);
	//SetConsoleCP(1251);

	std::string name_file;
	std::cout << "Input file: "sv;
	std::getline(std::cin, name_file);

	ManagerGroup mg;

	Load(name_file, mg);

	std::cout << name_file;

	std::cout << "Input file to output: "sv;
	std::getline(std::cin, name_file);

	PrintToFile(name_file, mg);

	return 0;
}
