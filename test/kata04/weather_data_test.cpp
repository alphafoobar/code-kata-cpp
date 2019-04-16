#include <gtest/gtest.h>

#include "../../src/kata04/weather_data.h"

TEST(Kata04_WeatherData, HandlesAsterixData) {
    std::optional<WeatherData> weatherData = WeatherData::newWeatherData(
            "  26  97*   64    81          70.4       0.00 H       050  5.1 200  12  4.0 107 45 1014.9");
    EXPECT_EQ(33, weatherData.value().difference());
}

TEST(Kata04_WeatherData, HandlesNormalData) {
    std::optional<WeatherData> weatherData = WeatherData::newWeatherData(
            "   5  90    66    78          68.3       0.00 TFH     220  8.3 260  12  6.9  84 55 1014.4");
    EXPECT_EQ(24, weatherData.value().difference());
}

TEST(Kata04_WeatherData, SkipsInvalidData) {
    std::optional<WeatherData> weatherData = WeatherData::newWeatherData(
            "  mo  82.9  60.5  71.7    16  58.8       0.00              6.9          5.3");
    EXPECT_EQ(false, weatherData.has_value());
}

TEST(Kata04_WeatherData, SkipsEmptyData) {
    std::optional<WeatherData> weatherData = WeatherData::newWeatherData("  ");
    EXPECT_EQ(false, weatherData.has_value());
}
