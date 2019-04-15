#include <gtest/gtest.h>

#include "../../src/kata04/weather_data_munger.h"

TEST(Kata04_WeatherMunger, HandlesWeatherFile) {
    WeatherDataMunger munger = WeatherDataMunger::readFile("../../test/resources/weather.dat");
    EXPECT_EQ("14", munger.smallestDifference().value().label());
}
