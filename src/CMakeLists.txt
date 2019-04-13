add_library(cpp kata02/binary_search.cpp kata02/binary_search.h
        kata04/read_file.cpp kata04/read_file.h
        )

# Include code-coverage settings:
target_link_libraries(cpp PUBLIC coverage_config)
