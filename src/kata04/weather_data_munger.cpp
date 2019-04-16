#include "weather_data_munger.h"

optional<WeatherData> WeatherDataMunger::smallestDifference() {
    optional<WeatherData> smallestData;
    for (const WeatherData &weatherData : data) {
        if (!smallestData.has_value() || weatherData.difference() < smallestData.value().difference()) {
            smallestData.emplace(weatherData);
        }
    }
    return smallestData;
}