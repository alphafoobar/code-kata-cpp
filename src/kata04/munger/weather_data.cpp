#include "weather_data.h"

WeatherData::WeatherData(int day, int min, int max) :
        day(day), min(min), max(max) {}

int WeatherData::label() const {
    return day;
}

int WeatherData::difference() const {
    return abs(min - max);
}

std::optional<WeatherData>
WeatherData::anOptionalWeather(const std::string &day, const std::string &min, const std::string &max) {
    auto day_optional = an_int(day);
    auto min_optional = an_int(min);
    auto max_optional = an_int(max);

    if (day_optional.has_value() && min_optional.has_value() && max_optional.has_value()) {
        return {{day_optional.value(), min_optional.value(), max_optional.value()}};
    }
    return {}; // Empty optional.
}

/**
 * Static builder for weather data. Builds an optional if valid data included in the input string.
 */
std::optional<WeatherData> WeatherData::newWeatherData(const std::string &data) {
    std::stringstream ss{data};
    std::string day, min, max;
    ss >> day >> min >> max;

    return anOptionalWeather(day, min, max);
}
