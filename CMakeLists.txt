cmake_minimum_required(VERSION 3.17)
project(genes)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

add_executable(genes WIN32
        src/main.cpp
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
        include/evolutiong_game/Cell/Genes.h
        src/QT/mainwindow.cpp
        src/QT/mainwindow.h
        src/QT/mainwindow.ui include/evolutiong_game/enums.cpp)

#if (NOT CMAKE_PREFIX_PATH)
#    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
#            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
#endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})