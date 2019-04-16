#include "read_file.h"

std::vector<std::string> to_data(const std::string &filename) {
    std::ifstream in_file(filename);
    std::vector<std::string> str_vector;

    std::string line;
    while (std::getline(in_file, line)) {
        str_vector.push_back(line);
    }
    return str_vector;
}