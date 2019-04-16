#include "weather_data_munger.h"

std::optional<WeatherData> WeatherDataMunger::smallestDifference() {
    std::optional<WeatherData> smallestData;
    for (const WeatherData &weatherData : data) {
        if (!smallestData.has_value() || weatherData.difference() < smallestData.value().difference()) {
            smallestData.emplace(weatherData);
        }
    }
    return smallestData;
}

WeatherDataMunger read_weather_file(const std::string &filename) {
    std::vector<WeatherData> vector;
    std::vector<std::string> file_data = to_data(filename);

    for (const std::string &row: file_data) {
        auto anOptional = WeatherData::newWeatherData(row);
        if (anOptional.has_value()) {
            vector.push_back(anOptional.value());
        }
    }
    return WeatherDataMunger::newWeatherDataMunger(vector);
}