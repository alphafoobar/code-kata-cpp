#ifndef CODE_KATA_CPP_MUNGER_H
#define CODE_KATA_CPP_MUNGER_H

#include <string>
#include <vector>
#include <functional>
#include <optional>

template<typename T>
class Munger {

protected:
    const std::vector<T> data;

    explicit Munger(const std::vector<T> &data) : data(data) {}

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
        std::optional<T> smallestData;
        for (const T &data : data) {
            if (!smallestData.has_value() || data.difference() < smallestData.value().difference()) {
                smallestData.emplace(data);
            }
        }
        return smallestData;
    }
};

#endif //CODE_KATA_CPP_MUNGER_H
