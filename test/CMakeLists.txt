cmake_minimum_required(VERSION 3.19)
project(test)

set(CMAKE_CXX_STANDARD 20)

#include(ExternalProject)
find_package(doctest REQUIRED)


# Expose required variable (DOCTEST_INCLUDE_DIR) to parent scope
set(DOCTEST_INCLUDE_DIR ${source_dir}/doctest CACHE INTERNAL "Path to include folder for doctest")

add_executable(test main.cpp
        ../include/evolutiong_game/Cell/Coordinate.h
        ../include/evolutiong_game/Cell/Coordinate.cpp
        ../include/evolutiong_game/Cell/Genes.h
        ../include/evolutiong_game/Cell/Genes.cpp
        TestGenes.cpp
        TestGenes.h)
target_link_libraries(test PRIVATE doctest::doctest)