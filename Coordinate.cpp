//
// Created by ivantretyak on 25.03.2021.
//

#include "Coordinate.h"


Coordinate::Coordinate(std::vector<int> c) {
    Coordinate::xy = std::move(c);
}

std::vector<int> Coordinate::getXY() {
    return Coordinate::xy;
}

Coordinate::Coordinate() {
    Coordinate::xy = {0, 0};
}
