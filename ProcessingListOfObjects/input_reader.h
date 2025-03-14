#pragma once

#include <fstream>
#include <filesystem>
#include <iostream>
#include <vector>
#include <string>
#include <deque>

#include "object.h"
#include "group.h"
#include "geo.h"

class ParsingError : public std::runtime_error {
public:
    using runtime_error::runtime_error;
};

std::ostream& operator<<(std::ostream& out, const Coordinates& coord);

std::ostream& operator<<(std::ostream& out, const Object& obj);

std::vector<std::string> SplitToWords(const std::string& text);

void Load(std::istream& input, ManagerGroup& mg);

void PrintToFile(const std::string& input, ManagerGroup& mg);
