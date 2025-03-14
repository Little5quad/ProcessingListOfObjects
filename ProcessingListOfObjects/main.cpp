#include <iostream>

#include "input_reader.h"

using std::filesystem::path;

path operator""_p(const char* data, std::size_t sz) {
	return path(data, data + sz);
}

int main()
{
	std::cout << "Hello CMake." << std::endl;
	return 0;
}
