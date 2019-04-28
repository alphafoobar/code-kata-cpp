#ifndef CODE_KATA_CPP_MUNGER_H
#define CODE_KATA_CPP_MUNGER_H

#include <string>
#include <vector>
#include <functional>
#include <optional>

template<typename T>
class Munger {

protected:
    const std::vector<T> data_vector;

    explicit Munger(const std::vector<T> &data) : data_vector(data) {}

public:
    /**
     * Find the smallest difference in the available data.
     *
     * Template functions implementation belong in the header file.
     * See: https://isocpp.org/wiki/faq/templates#separate-template-fn-defn-from-decl
     *
     * @return Optional<T> representing the smallest difference, if anything to search. Otherwise Optional.empty.
     */
    std::optional<T> smallestDifference() {
        std::optional<T> smallest_data;
        for (const T &data : this->data_vector) {
            if (!smallest_data.has_value() || data.difference() < smallest_data.value().difference()) {
                smallest_data.emplace(data);
            }
        }
        return smallest_data;
    }
};

#endif //CODE_KATA_CPP_MUNGER_H
