add_library(cpp kata02/binary_search.cpp kata02/binary_search.h
        file/read_file.cpp file/read_file.h
        kata04/munger/weather_data.cpp kata04/munger/weather_data.h
        kata04/munger/weather_data_munger.cpp kata04/munger/weather_data_munger.h
        kata04/munger/data.h
        kata04/munger/munger.h
        kata04/munger/football_data.cpp kata04/munger/football_data.h
        kata04/munger/football_munger.cpp kata04/munger/football_munger.h
        kata04/strings.cpp kata04/strings.h kata05/Dictionary.cpp kata05/Dictionary.h)

# Include code-coverage settings:
target_link_libraries(cpp PUBLIC coverage_config)
