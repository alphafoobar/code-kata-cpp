add_library(cpp kata02/binary_search.cpp kata02/binary_search.h
        kata04/read_file.cpp kata04/read_file.h
        kata04/munger/weather_data.cpp kata04/munger/weather_data.h
        kata04/munger/weather_data_munger.cpp kata04/munger/weather_data_munger.h
        kata04/munger/data.h
        kata04/munger/munger.h
        kata04/munger/football.cpp kata04/munger/football.h
        kata04/munger/football_munger.cpp kata04/munger/football_munger.h
        kata04/strings.cpp kata04/strings.h)

# Include code-coverage settings:
target_link_libraries(cpp PUBLIC coverage_config)
