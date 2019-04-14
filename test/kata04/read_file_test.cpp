#include <gtest/gtest.h>

#include "../../src/kata04/read_file.h"

vector<string> EMPTY_VECTOR = {};

std::string getCurrentWorkingDir() {
    char buff[FILENAME_MAX];
    getcwd(buff, FILENAME_MAX);
    std::string current_working_dir(buff);
    return current_working_dir;
}

void logWorkingDirectory() {
    std::cout << "Working directory: " << getCurrentWorkingDir() << std::endl;
}

TEST(Kata04_ReadFile, HandlesUnknownFile) {
    logWorkingDirectory();
    EXPECT_EQ(EMPTY_VECTOR, to_data("unknown file"));
}

TEST(Kata04_ReadFile, HandlesWeatherFile) {
    logWorkingDirectory();
    EXPECT_LT(0, to_data("../../test/resources/weather.dat").size());
}

TEST(Kata04_ReadFile, HandlesFootballFile) {
    logWorkingDirectory();
    EXPECT_LT(0, to_data("../../test/resources/football.dat").size());
}
