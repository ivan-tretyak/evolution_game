//
// Created by ivantretyak on 25.03.2021.
//

#ifndef GENES_CELL_H
#define GENES_CELL_H

#include "enums.h"
#include <random>
#include "Coordinate.h"

class Cell {
private:
    CellType type;
    Coordinate c;
public:
    Cell(Coordinate c);
    Cell();
    CellType getType();
};


#endif //GENES_CELL_H
