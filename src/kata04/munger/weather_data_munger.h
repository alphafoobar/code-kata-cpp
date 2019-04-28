#ifndef CODE_KATA_CPP_WEATHER_DATA_MUNGER_H
#define CODE_KATA_CPP_WEATHER_DATA_MUNGER_H

#include "munger.h"
#include "../../file/read_file.h" // #to_data(string filename)
#include "weather_data.h"

class WeatherDataMunger : public Munger<WeatherData> {

private:
    explicit WeatherDataMunger(const std::vector<WeatherData> &data);

public:
    static WeatherDataMunger newWeatherDataMunger(const std::vector<WeatherData> &data);
};

WeatherDataMunger read_weather_file(const std::string &filename);

#endif //CODE_KATA_CPP_WEATHER_DATA_MUNGER_H
