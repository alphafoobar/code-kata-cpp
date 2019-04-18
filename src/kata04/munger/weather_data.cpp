#include "weather_data.h"

WeatherData::WeatherData(int day, int min, int max) :
        day(day), min(min), max(max) {}

int WeatherData::label() const {
    return day;
}

int WeatherData::difference() const {
    return abs(min - max);
}

std::string strip_trailing_asterisk(const std::string &s) {
    const unsigned long new_length = s.size() - 1;
    if (new_length > 0 && new_length < s.size() && s.at(new_length) == '*') {
        return s.substr(0, new_length);
    }
    return s;
}

std::optional<int> WeatherData::anInt(const std::string &day) {
    const std::string new_day = strip_trailing_asterisk(day);
    if (is_number(new_day)) {
        return stoi(new_day);
    }
    return {}; // Empty optional.
}

std::optional<WeatherData>
WeatherData::anOptionalWeather(const std::string &day, const std::string &min, const std::string &max) {
    auto day_optional = anInt(day);
    auto min_optional = anInt(min);
    auto max_optional = anInt(max);

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
