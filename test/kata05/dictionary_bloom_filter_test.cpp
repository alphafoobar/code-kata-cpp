#include <gtest/gtest.h>

#include "../../../src/kata05/dictionary.h"

TEST(Kata05_Dictionary, ReadDictionary) {
    Dictionary dictionary = Dictionary::read_dictionary_file("../../test/resources/wordlist.txt");
    EXPECT_EQ(true, dictionary.test_word("test"));
}

TEST(Kata05_Dictionary, FindTrickyWord) {
    Dictionary dictionary = Dictionary::read_dictionary_file("../../test/resources/wordlist.txt");
    EXPECT_EQ(true, dictionary.test_word("beefburger's"));
}

// There should be some GAPS in the dictionary to all some words to MISS.
TEST(Kata05_Dictionary, TryMissingWordIncorrectlyAssumed) {
    Dictionary dictionary = Dictionary::read_dictionary_file("../../test/resources/wordlist.txt");
    dictionary.percentage_miss();

    // With a smaller dictionary, 100% filled.
    EXPECT_EQ(true, dictionary.test_word("F@@@"));
}
