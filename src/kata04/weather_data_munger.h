#ifndef CODE_KATA_CPP_WEATHER_DATA_MUNGER_H
#define CODE_KATA_CPP_WEATHER_DATA_MUNGER_H

#include "munger.h"
#include "read_file.h" // #to_data(string filename)
#include "weather_data.h"

class WeatherDataMunger : public Munger<WeatherData> {

private:
    explicit WeatherDataMunger(std::vector<WeatherData> &data) : Munger{data} {}

public:
    std::optional<WeatherData> smallestDifference() override;

    static WeatherDataMunger newWeatherDataMunger(std::vector<WeatherData> &data) {
        return WeatherDataMunger{data};
    }
};

WeatherDataMunger read_weather_file(const std::string &filename);

#endif //CODE_KATA_CPP_WEATHER_DATA_MUNGER_H
