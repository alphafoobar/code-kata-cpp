#ifndef CODE_KATA_CPP_WEATHER_DATA_H
#define CODE_KATA_CPP_WEATHER_DATA_H

#include <string>
#include <optional>

using namespace std;

class WeatherData {
private:
    const int day;
    const int min;
    const int max;

    WeatherData(int day, int min, int max);

    static optional<int> anInt(const string &day);

public:
    int difference();

    static optional<WeatherData> newWeatherData(string data);

    static optional<WeatherData> anOptional(const string &day, const string &min, const string &max);
};

#endif //CODE_KATA_CPP_WEATHER_DATA_H
