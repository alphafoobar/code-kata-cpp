add_library(cpp kata02/binary_search.cpp kata02/binary_search.h
        kata04/read_file.cpp kata04/read_file.h
        kata04/weather_data.cpp kata04/weather_data.h
        kata04/weather_data_munger.cpp kata04/weather_data_munger.h
        kata04/weather_data_munger.cpp
        kata04/data.h kata04/munger.h
        kata04/football.cpp kata04/football.h kata04/strings.h kata04/strings.cpp)

# Include code-coverage settings:
target_link_libraries(cpp PUBLIC coverage_config)
