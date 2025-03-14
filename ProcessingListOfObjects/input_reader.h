#pragma once

#include <fstream>
#include <filesystem>
#include <iostream>
#include <vector>
#include <string>

#include "object.h"
#include "group.h"

class ParsingError : public std::runtime_error {
public:
    using runtime_error::runtime_error;
};

std::vector<std::string> SplitToWords(const std::string& text);

void Load(std::istream& input, ManagerGroup& mg);