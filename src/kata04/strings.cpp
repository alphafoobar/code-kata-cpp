#include "strings.h"

bool is_number(const std::string &s) {
    std::string::const_iterator it = s.begin();
    for (; it != s.end() && std::isdigit(*it); it++);
    return !s.empty() && it == s.end();
}