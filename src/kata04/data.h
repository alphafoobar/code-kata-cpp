#ifndef CODE_KATA_CPP_DATA_H
#define CODE_KATA_CPP_DATA_H

#include <string>

#include "data.h"

using namespace std;


class Data {

public:
    virtual string label() = 0;

    virtual int difference() = 0;
};


#endif //CODE_KATA_CPP_DATA_H
