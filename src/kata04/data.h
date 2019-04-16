#ifndef CODE_KATA_CPP_DATA_H
#define CODE_KATA_CPP_DATA_H

#include <string>

#include "data.h"

using namespace std;

template<class T>
class Data {

public:
    virtual T label() const = 0;

    virtual int difference() const = 0;
};


#endif //CODE_KATA_CPP_DATA_H
