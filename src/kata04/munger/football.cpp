#include "football.h"

Football::Football(const std::string &name, int points_for, int points_against) :
        name(name), points_for(points_for), points_against(points_against) {}

std::string Football::label() const {
    return name;
}

int Football::difference() const {
    return abs(points_for - points_against);
}

std::optional<int> Football::anInt(const std::string &points) {
    if (is_number(points)) {
        return stoi(points);
    }
    return {}; // Empty optional.
}

std::optional<Football>
Football::anOptionalFootball(const std::string &name, const std::string &points_for,
                             const std::string &points_against) {
    auto for_optional = anInt(points_for);
    auto against_optional = anInt(points_against);

    if (for_optional.has_value() && against_optional.has_value()) {
        return {{name, for_optional.value(), against_optional.value()}};
    }
    return {}; // Empty optional.
}

/**
 * Build an optional if valid data included in the input string.
 */
std::optional<Football> Football::newFootball(const std::string &data) {
    std::stringstream ss{data};
    std::string name, points_for, points_against;
    std::string no_op; // generic field for something
    ss >> no_op >> name >> no_op >> no_op >> no_op >> no_op >> points_for >> no_op >> points_against;

    return anOptionalFootball(name, points_for, points_against);
}
