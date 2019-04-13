#include <gtest/gtest.h>

#include "../../src/kata02/binary_search.h"

TEST(Kata02_BinarySearch, HandlesEmptyArray) {
    int array[] = {};
    EXPECT_EQ(-1, chop(1, array, 0));
}

TEST(Kata02_BinarySearch, HandlesArrayWithSingleItem) {
    int array[] = {1};
    EXPECT_EQ(0, chop(1, array, 1));
    EXPECT_EQ(-1, chop(3, array, 1));
}

TEST(Kata02_BinarySearch, HandlesArrayWithThreeItems) {
    int array[] = {1, 3, 5};
    EXPECT_EQ(0, chop(1, array, 3));
    EXPECT_EQ(1, chop(3, array, 3));
    EXPECT_EQ(2, chop(5, array, 3));
    EXPECT_EQ(-1, chop(0, array, 3));
    EXPECT_EQ(-1, chop(2, array, 3));
    EXPECT_EQ(-1, chop(4, array, 3));
    EXPECT_EQ(-1, chop(6, array, 3));
}

TEST(Kata02_BinarySearch, HandlesArrayWithFourItems) {
    int array[] = {1, 3, 5, 7};
    EXPECT_EQ(0, chop(1, array, 4));
    EXPECT_EQ(1, chop(3, array, 4));
    EXPECT_EQ(2, chop(5, array, 4));
    EXPECT_EQ(3, chop(7, array, 4));
    EXPECT_EQ(-1, chop(0, array, 4));
    EXPECT_EQ(-1, chop(2, array, 4));
    EXPECT_EQ(-1, chop(4, array, 4));
    EXPECT_EQ(-1, chop(6, array, 4));
    EXPECT_EQ(-1, chop(6, array, 4));
    EXPECT_EQ(-1, chop(8, array, 4));
}
