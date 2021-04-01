//
// Created by ivantretyak on 25.03.2021.
//

#ifndef GENES_CELL_H
#define GENES_CELL_H

#include "../enums.h"
#include "Coordinate.h"
#include "Genes.h"

class Cell {
private:
    Coordinate c;
    int energy = 125;
    bool moving = false;
    Genes genes;
public:
    Cell(Coordinate c, Genes g);
    Cell();
    CellType getType();
    Coordinate getCoordinate();
    Coordinate move(SectionType up, SectionType left, SectionType right, SectionType down, unsigned int size);
    void changeCoordinate(Coordinate coord);
    void eat(int e);
    void switchMoving();
    bool getMoving() const;
};


#endif //GENES_CELL_H
