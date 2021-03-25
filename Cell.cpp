//
// Created by ivantretyak on 25.03.2021.
//

#include "Cell.h"

#include <utility>

Cell::Cell(Coordinate c) {
    Cell::c = std::move(c);
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<> types(0, 1);
    Cell::type = static_cast<CellType>(types(gen));
}

CellType Cell::getType() {
    return type;
}

Cell::Cell() {
    Cell::c = Coordinate();
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<> types(0, 1);
    Cell::type = static_cast<CellType>(types(gen));
}
