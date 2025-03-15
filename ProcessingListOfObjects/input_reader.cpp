#include "input_reader.h"

using std::filesystem::path;
using namespace std::literals;

path operator""_p(const char* data, std::size_t sz) {
    return path(data, data + sz);
}

std::ostream& operator<<(std::ostream& out, const Coordinates& coord) {
    return out << coord.x_ << " " << coord.y_;
}

std::ostream& operator<<(std::ostream& out, const Object& obj) {
    return out << obj.GetName() << " " << obj.GetCoordinates() << " " << obj.GetType() << " " << obj.GetTime() << "\n";
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

void Load(const std::string& input, ManagerGroup& mg) {
    std::ifstream input_file(input, std::ios::binary);
    if (input_file) {
        
        std::string c;

        while (std::getline(input_file, c)) {
            std::cout << c << std::endl;
            std::vector<std::string> tmp = SplitToWords(c);
            if (tmp.size() != 5) {
                throw std::logic_error("Error in file");
            }
            try {
                mg.AddToList(tmp[0], { std::stod(tmp[1]), std::stod(tmp[2]) }, tmp[3], std::stod(tmp[4]));
            }
            catch (...) {
                throw ParsingError("Failed to convert ");
            }
        }
        
        std::cout << "yes\n";
    }
    else {
        throw std::logic_error("No such file");
    }
}


void PrintToFile(const std::string& input, ManagerGroup& mg) {
    std::ofstream output_file(input, std::ios::binary | std::ios::app);
    if (output_file) {
        const auto& all_objects = mg.GetAllObjects();
        for (const auto& obj : all_objects) {
            output_file << obj;
        }
        output_file << "АБВГДежзи"s;
    }
}

void SaveToFile(const std::string& input, ManagerGroup& mg, SortingCriteria crit){
    std::ofstream output_file(input, std::ios::binary | std::ios::app);
    if (output_file) {

    }
}

