#include <gtest/gtest.h>

#include "../../src/kata05/Dictionary.h"

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
    // With a larger dictionary more gaps.
    dictionary.percentage_miss();

    // With a smaller dictionary, 100% filled. But should find a large enough size such that we can still miss.
    EXPECT_EQ(false, dictionary.test_word("F@@@@"));
}
