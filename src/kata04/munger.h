#ifndef CODE_KATA_CPP_MUNGER_H
#define CODE_KATA_CPP_MUNGER_H

#include <string>
#include <vector>
#include <functional>
#include <optional>

template<class T>
class Munger {

protected:
    const std::vector<T> data;

    explicit Munger(std::vector<T> &data) : data(data) {}

public:
    virtual std::optional<T> smallestDifference() = 0;
};

#endif //CODE_KATA_CPP_MUNGER_H
