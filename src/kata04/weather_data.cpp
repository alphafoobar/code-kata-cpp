#include <sstream>

#include "weather_data.h"

int WeatherData::label() const {
    return day;
}

int WeatherData::difference() const {
    return abs(min - max);
}

bool is_number(const string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

string strip_trailing_asterisk(const string &s) {
    const unsigned long new_length = s.size() - 1;
    if (new_length > 0 && new_length < s.size() && s.at(new_length) == '*') {
        return s.substr(0, new_length);
    }
    return s;
}

optional<int> WeatherData::anInt(const string &day) {
    const string new_day = strip_trailing_asterisk(day);
    if (is_number(new_day)) {
        return stoi(new_day);
    }
    return {}; // Empty optional.
}

optional<WeatherData> WeatherData::anOptional(const string &day, const string &min, const string &max) {
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
optional<WeatherData> WeatherData::newWeatherData(const string &data) {
    stringstream ss{data};
    string day, min, max;
    ss >> day >> min >> max;

    return anOptional(day, min, max);
}
