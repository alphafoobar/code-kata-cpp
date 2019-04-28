#include "Dictionary.h"
#include "../file/read_file.h"

Dictionary::Dictionary() {
    // Initialize filter array to zero.
    for (bool &i : filter) {
        i = false;
    }
}

Dictionary Dictionary::read_dictionary_file(const std::string &filename) {
    Dictionary dictionary{};
    std::vector<std::string> file_data = to_data(filename);

    for (const std::string &row: file_data) {
        dictionary.add_word(row);
    }
    return dictionary;
}

int Dictionary::algo_one(const std::string &test) {
    unsigned int hash = 1;
    for (char i : test) {
        hash = (hash * 37 + (int) i);
    }
    return hash % BLOOM_DICTIONARY_SIZE;
}

int Dictionary::add_word(const std::string &word) {
    const auto result = algo_one(word);
    this->filter[result] = true;
    return result;
}

bool Dictionary::test_word(const std::string &word) {
    return this->filter[algo_one(word)];
}

double Dictionary::check_fill() {
    unsigned int count = 0;
    for (bool &i : filter) {
        if (i) {
            count++;
        }
    }
    return count * 100.0 / BLOOM_DICTIONARY_SIZE;
}

void Dictionary::percentage_miss() {
    printf("%f %% are taken\n", check_fill());
}
