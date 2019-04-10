add_library(cpp kata02/binary_search.cpp kata02/binary_search.h)

# Include code-coverage settings:
target_link_libraries(cpp PUBLIC coverage_config)
