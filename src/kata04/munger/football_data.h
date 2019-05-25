#ifndef CODE_KATA_CPP_FOOTBALL_DATA_H
#define CODE_KATA_CPP_FOOTBALL_DATA_H

#include <sstream>
#include <string>
#include <optional>

#include "data.h"
#include "../strings.h"

class Football : public Data<std::string> {
private:
    const std::string name;
    const int points_for;
    const int points_against;

    Football(const std::string &name, int points_for, int points_against);

    static std::optional<int> anInt(const std::string &string);

public:
    std::string label() const override;

    int difference() const override;

    static std::optional<Football> newFootball(const std::string &data);

    static std::optional<Football>
    anOptionalFootball(const std::string &name, const std::string &points_for, const std::string &points_against);
};

#endif //CODE_KATA_CPP_FOOTBALL_DATA_H
