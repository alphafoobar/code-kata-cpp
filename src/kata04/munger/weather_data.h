#ifndef CODE_KATA_CPP_WEATHER_DATA_H
#define CODE_KATA_CPP_WEATHER_DATA_H

#include <sstream>
#include <string>
#include <optional>

#include "data.h"
#include "../strings.h"

class WeatherData : public Data<int> {
private:
    const int day;
    const int min;
    const int max;

    WeatherData(int day, int min, int max);

    static std::optional<int> anInt(const std::string &day);

public:
    int label() const override;

    int difference() const override;

    static std::optional<WeatherData> newWeatherData(const std::string &data);

    static std::optional<WeatherData>
    anOptionalWeather(const std::string &day, const std::string &min, const std::string &max);
};

#endif //CODE_KATA_CPP_WEATHER_DATA_H
