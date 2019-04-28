#ifndef CODE_KATA_CPP_DICTIONARY_H
#define CODE_KATA_CPP_DICTIONARY_H

#ifndef BLOOM_DICTIONARY_SIZE
#define BLOOM_DICTIONARY_SIZE 10007
#endif //BLOOM_DICTIONARY_SIZE

#include <vector>
#include <string>

class Dictionary {
    bool filter[BLOOM_DICTIONARY_SIZE];

    explicit Dictionary();

    int algo_one(const std::string &test);

    double check_fill();

public:
    int add_word(const std::string &test);

    bool test_word(const std::string &test);

    void percentage_miss();

    static
    Dictionary read_dictionary_file(const std::string &filename);

};

#endif //CODE_KATA_CPP_DICTIONARY_H
