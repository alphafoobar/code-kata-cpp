include(GoogleTest)
include_directories(
        googletest-1.8.1/googletest/include googletest-1.8.1/googletest
        googletest-1.8.1/googlemock/include googletest-1.8.1/googlemock
)

add_subdirectory(googletest-1.8.1)

add_executable(runCodeKataTests
        test_main.cpp
        kata02/binary_search_test.cpp
        file/read_file_test.cpp
        kata04/munger/weather_data_test.cpp
        kata04/munger/weather_data_munger_test.cpp
        kata04/munger/football_test.cpp
        kata04/munger/football_munger_test.cpp
        kata05/dictionary_bloom_filter_test.cpp
        )

target_link_libraries(runCodeKataTests gtest gtest_main gmock gmock_main --coverage)
target_link_libraries(runCodeKataTests cpp --coverage)

gtest_discover_tests(runCodeKataTests)