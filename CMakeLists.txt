cmake_minimum_required(VERSION 2.8)

project(CalculadoraBIR)


## DEFINE MAIN PATHS
set(bin_path ${PROJECT_BINARY_DIR}/bin)
set(source_path ${PROJECT_SOURCE_DIR}/src)
set(test_path ${PROJECT_SOURCE_DIR}/test)

## DEFINE BINARY DESTINE
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${bin_path})

add_executable(binary_tree src/binary_tree_main.cpp)
target_link_libraries(binary_tree ${SOURCE_LIBS})
