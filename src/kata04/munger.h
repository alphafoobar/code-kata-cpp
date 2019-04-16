#ifndef CODE_KATA_CPP_MUNGER_H
#define CODE_KATA_CPP_MUNGER_H

#include <optional>

using namespace std;

template<class T>
class Munger {

protected:
    const vector<WeatherData> data;

    explicit Munger(vector<WeatherData> &data) : data(data) {}

public:
    virtual optional<T> smallestDifference() = 0;
};

#endif //CODE_KATA_CPP_MUNGER_H
