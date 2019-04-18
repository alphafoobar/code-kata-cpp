#include "weather_data_munger.h"

WeatherDataMunger::WeatherDataMunger(const std::vector<WeatherData> &data) : Munger{data} {}

WeatherDataMunger WeatherDataMunger::newWeatherDataMunger(const std::vector<WeatherData> &data) {
    return WeatherDataMunger{data};
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