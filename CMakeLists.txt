cmake_minimum_required(VERSION 3.17)
project(genes)

set(CMAKE_CXX_STANDARD 20)

add_executable(genes main.cpp Coordinate.cpp Coordinate.h Food.cpp Food.h enums.h Cell.cpp Cell.h Section.cpp Section.h Field.cpp Field.h)