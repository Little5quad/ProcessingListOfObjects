#include "input_reader.h"

#include <iomanip>

using std::filesystem::path;
using namespace std::literals;

path operator""_p(const char* data, std::size_t sz) {
    return path(data, data + sz);
}

std::ostream& operator<<(std::ostream& out, const Coordinates& coord) {
    return out << coord.x_ << " " << coord.y_;
}

std::ostream& operator<<(std::ostream& out, const Object& obj) {
    return out << obj.GetName() << " " << obj.GetCoordinates() << " " << obj.GetType() << " " << std::setprecision(15) << obj.GetTime() << "\n";
}

std::ostream& operator<<(std::ostream& out, const SubGroup& subgroup) {
    for (const auto& obj: subgroup.GetConstGroup()) {
        out << *obj;
    }
    return out;
}

std::vector<std::string> SplitToWords(const std::string& text) {
    std::vector<std::string> words;
    std::string word;
    for (const char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}

void Load(const std::string& file_name, ManagerGroup& mg) {
    std::ifstream input_file(file_name/*, std::ios::binary*/);
    if (input_file) {
        std::string c;

        while (std::getline(input_file, c)) {
            std::vector<std::string> tmp = SplitToWords(c);
            if (tmp.size() != 5) {
                throw ParsingError("Error in file"s);
            }
            try {
                mg.AddToList(tmp[0], { std::stod(tmp[1]), std::stod(tmp[2]) }, tmp[3], std::stod(tmp[4]));
            }
            catch (...) {
                throw ParsingError("Failed to convert "s);
            }
        }
    }
    else {
        throw std::logic_error("No such file"s);
    }
}


void PrintToFile(const std::string& file_name, ManagerGroup& mg) {
    std::ofstream output_file(file_name, /*std::ios::binary |*/ std::ios::app);
    if (output_file) {
        const auto& all_objects = mg.GetAllObjects();
        for (const auto& obj : all_objects) {
            output_file << obj;
        }
    }
    else {
        throw std::logic_error("No such file"s);
    }
}

void SaveToFile(const std::string& file_name, ManagerGroup& mg, const std::string& name_group, SortingCriteria crit){
    std::ofstream output_file(file_name, /*std::ios::binary |*/ std::ios::app);
    if (output_file) {
        if (const auto& tmp_gr = mg.GetGroup(name_group); tmp_gr.GetNameGroup() != "" && tmp_gr.GetSubgroups().size() != 0) {
            output_file << "Сортировка: "s << name_group << "\n";
            for (const auto& [name, subgroup] : tmp_gr.GetSubgroups()) {
                output_file << "Подгруппа: " << name << "\n";
                output_file << subgroup;
            }
            output_file << "\n";
        }
        else {
            mg.CreateGroup(crit);
            SaveToFile(file_name, mg, name_group, crit);
        }
    }
    else {
        throw std::logic_error("No such file"s);
    }
}

