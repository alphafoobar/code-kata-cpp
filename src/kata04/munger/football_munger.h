#ifndef CODE_KATA_CPP_FOOTBALL_MUNGER_H
#define CODE_KATA_CPP_FOOTBALL_MUNGER_H


#include "munger.h"
#include "football_data.h"
#include "../../file/read_file.h" // #to_data(string filename)

class FootballMunger : public Munger<Football> {

private:
    explicit FootballMunger(const std::vector<Football> &data);

public:
    static FootballMunger newFootballMunger(const std::vector<Football> &data);
};

FootballMunger read_football_file(const std::string &filename);

#endif //CODE_KATA_CPP_FOOTBALL_MUNGER_H
