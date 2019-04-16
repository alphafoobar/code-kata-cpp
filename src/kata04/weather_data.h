#ifndef CODE_KATA_CPP_WEATHER_DATA_H
#define CODE_KATA_CPP_WEATHER_DATA_H

#include <string>
#include <optional>

#include "data.h"

using namespace std;

class WeatherData : public Data<int> {
private:
    const int day;
    const int min;
    const int max;

    WeatherData(int day, int min, int max) :
            day(day), min(min), max(max) {}

    static optional<int> anInt(const string &day);

public:
    int label() const;

    int difference() const;

    static optional<WeatherData> newWeatherData(const string &data);

    static optional<WeatherData> anOptional(const string &day, const string &min, const string &max);
};

#endif //CODE_KATA_CPP_WEATHER_DATA_H
