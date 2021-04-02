cmake_minimum_required(VERSION 3.17)
project(genes)

set(CMAKE_CXX_STANDARD 20)

add_executable(genes src/main.cpp
        include/evolutiong_game/Cell/Coordinate.cpp
        include/evolutiong_game/Cell/Coordinate.h
        include/evolutiong_game/Food.cpp
        include/evolutiong_game/Food.h
        include/evolutiong_game/enums.h
        include/evolutiong_game/Cell/Cell.cpp
        include/evolutiong_game/Cell/Cell.h
        include/evolutiong_game/Section.cpp
        include/evolutiong_game/Section.h
        include/evolutiong_game/Field.cpp
        include/evolutiong_game/Field.h
        include/evolutiong_game/Cell/Genes.cpp
        include/evolutiong_game/Cell/Genes.h)