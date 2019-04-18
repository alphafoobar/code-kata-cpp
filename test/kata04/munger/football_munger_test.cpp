#include <gtest/gtest.h>

#include "../../../src/kata04/munger/football_munger.h"

TEST(Kata04_FootballMunger, HandlesFootballFile) {
    FootballMunger munger = read_football_file("../../test/resources/football.dat");
    EXPECT_EQ("Aston_Villa", munger.smallestDifference().value().label());
}
