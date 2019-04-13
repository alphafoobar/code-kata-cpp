#include <fstream>

#include "read_file.h"

using namespace std;

vector<string> to_data(string filename) {
    ifstream in_file(filename);
    vector<string> str_vector = {};

    string line;
    while (getline(in_file, line)) {
        str_vector.push_back(line);
    }
    return str_vector;
}