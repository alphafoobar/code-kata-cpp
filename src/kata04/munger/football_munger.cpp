#include "football_munger.h"

FootballMunger::FootballMunger(const std::vector<Football> &data) : Munger(data) {}

FootballMunger FootballMunger::newFootballMunger(const std::vector<Football> &data) {
    return FootballMunger{data};
}

FootballMunger read_football_file(const std::string &filename) {
    std::vector<Football> vector;
    std::vector<std::string> file_data = to_data(filename);

    for (const std::string &row: file_data) {
        auto anOptional = Football::newFootball(row);
        if (anOptional.has_value()) {
            vector.push_back(anOptional.value());
        }
    }
    return FootballMunger::newFootballMunger(vector);
}
