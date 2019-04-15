#include <utility>

#ifndef CODE_KATA_CPP_WEATHER_DATA_MUNGER_H
#define CODE_KATA_CPP_WEATHER_DATA_MUNGER_H

#include <vector>

#include "weather_data.h"
#include "read_file.h"

using namespace std;

class WeatherDataMunger {

private:
    vector<WeatherData> data;

    WeatherDataMunger(vector<WeatherData> data) : data(move(data)) {}

public:
    optional<WeatherData> smallestDifference();

    static WeatherDataMunger readFile(const string &filename) {
        vector<WeatherData> weather_vector;
        vector<string> file_data = to_data(filename);

        for (const string &row: file_data) {
            auto weatherData = WeatherData::newWeatherData(row);
            if (weatherData.has_value()) {
                weather_vector.push_back(weatherData.value());
            }
        }

        return weather_vector;
    }
};


#endif //CODE_KATA_CPP_WEATHER_DATA_MUNGER_H
