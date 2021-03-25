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

std::vector<int> Coordinate::getNewCoordinate(unsigned int s, Direction arrow) {
    std::vector<int> newCoordinate;
    switch (arrow) {
        case up: {
            newCoordinate = {xy[0], xy[1] - 1};
            break;
        }
        case right: {
            newCoordinate = {xy[0] + 1, xy[1]};
            break;
        }
        case down: {
            newCoordinate = {xy[0], xy[1] - 1};
            break;
        }
        case left: {
            newCoordinate = {xy[0] -Added move  1, xy[1]};
            break;
        }
    }

    if (newCoordinate[0] >= s) {
        return {0, newCoordinate[1]};
    }
    if (newCoordinate[0] < 0) {
        return {static_cast<int>(s - 1), newCoordinate[1]};
    }
    if (newCoordinate[1] >= s) {
        return {newCoordinate[0], 0};
    }
    if (newCoordinate[1] < 0) {
        return {newCoordinate[0], static_cast<int>(s - 1)};
    }
    return newCoordinate;
}
