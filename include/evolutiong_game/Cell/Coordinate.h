//
// Created by ivantretyak on 25.03.2021.
//

#ifndef GENES_COORDINATE_H
#define GENES_COORDINATE_H

#include <vector>
#include <utility>
#include "../enums.h"


class Coordinate {
private:
    std::vector<int> xy;
public:
    Coordinate(std::vector<int> c);

    Coordinate();

    std::vector<int> getXY();

    std::vector<int> getNewCoordinate(Direction arrow);
};


#endif //GENES_COORDINATE_H
