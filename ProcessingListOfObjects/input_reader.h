﻿#pragma once

#include <fstream>
#include <filesystem>
#include <iostream>
#include <vector>
#include <string>

#include "object.h"
#include "group.h"
#include "geo.h"
#include "comparator.h"

class ParsingError : public std::runtime_error {
public:
    using runtime_error::runtime_error;
};

std::ostream& operator<<(std::ostream& out, const Coordinates& coord);

std::ostream& operator<<(std::ostream& out, const Object& obj);

std::vector<std::string> SplitToWords(const std::string& text);

void Load(const std::string& file_name, ManagerGroup& mg);

void PrintToFile(const std::string& file_name, ManagerGroup& mg);

void SaveToFile(const std::string& file_name, ManagerGroup& mg, const std::string& name_group, SortingCriteria crit);