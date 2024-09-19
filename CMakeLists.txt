cmake_minimum_required(VERSION 3.5)

project(SortingBenchmark)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5Charts REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_executable(SortingBenchmark main.cpp sorting_algorithms.cpp linked_list.cpp binary_search_tree.cpp benchmark.cpp)

target_link_libraries(SortingBenchmark Qt5::Charts Qt5::Widgets)
