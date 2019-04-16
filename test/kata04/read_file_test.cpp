#include <gtest/gtest.h>

#include "../../src/kata04/read_file.h"

std::vector<std::string> EMPTY_VECTOR = {};

TEST(Kata04_ReadFile, HandlesUnknownFile) {
    EXPECT_EQ(EMPTY_VECTOR, to_data("unknown file"));
}

TEST(Kata04_ReadFile, HandlesWeatherFile) {
    EXPECT_LT(0, to_data("../../test/resources/weather.dat").size());
}

TEST(Kata04_ReadFile, HandlesFootballFile) {
    EXPECT_LT(0, to_data("../../test/resources/football.dat").size());
}
