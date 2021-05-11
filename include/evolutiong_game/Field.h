//
// Created by ivantretyak on 25.03.2021.
//

#ifndef GENES_FIELD_H
#define GENES_FIELD_H

#include "Section.h"
#include <string>
#include <iostream>

class Field {
private:
    std::vector<std::vector<Section>> field;
    unsigned int size;
    long int steps = 0;

    void moving(int y, int x, Coordinate &newCoordinate, const std::vector<int> &newXY);

    void eating(int y, int x, const std::vector<int> &newXY);

    void hiting(int y, int x, const std::vector<int> &newXY);

    void createFood(int y, int x);

    void
    getAround(Coordinate &currentCoordinate, SectionType &upT, SectionType &downT, SectionType &rightT,
              SectionType &leftT);

public:
    Field(unsigned int s);

    void move();

    long int getSteps() const;

    std::vector<std::vector<Section>> getField();

    void switchingMoving();
};


#endif //GENES_FIELD_H
