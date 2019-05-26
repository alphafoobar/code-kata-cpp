#include "strings.h"

bool is_number(const std::string &s) {
    std::string::const_iterator it = s.begin();
    for (; it != s.end() && std::isdigit(*it); it++);
    return !s.empty() && it == s.end();
}

std::string strip_trailing_asterisk(const std::string &s) {
    const unsigned long new_length = s.size() - 1;
    if (new_length > 0 && new_length < s.size() && s.at(new_length) == '*') {
        return s.substr(0, new_length);
    }
    return s;
}

std::optional<int> an_int(const std::string &value) {
    const std::string new_value = strip_trailing_asterisk(value);
    if (is_number(new_value)) {
        return stoi(new_value);
    }
    return {}; // Empty optional.
}