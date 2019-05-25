#include <gtest/gtest.h>

#include "../../../src/kata04/munger/football_data.h"

TEST(Kata04_Football, ReadTeamName) {
    std::optional<Football> football = Football::newFootball(
            "    1. Arsenal         38    26   9   3    79  -  36    87");
    EXPECT_EQ("Arsenal", football.value().label());
}

TEST(Kata04_Football, HandlesNormalData) {
    std::optional<Football> football = Football::newFootball(
            "    1. Arsenal         38    26   9   3    79  -  36    87");
    EXPECT_EQ(43, football.value().difference());
}

TEST(Kata04_Football, SkipsInvalidData) {
    std::optional<Football> football = Football::newFootball(
            "       Team            P     W    L   D    F      A     Pts");
    EXPECT_EQ(false, football.has_value());
}

TEST(Kata04_Football, SkipsEmptyData) {
    std::optional<Football> football = Football::newFootball(
            "   -------------------------------------------------------");
    EXPECT_EQ(false, football.has_value());
}
