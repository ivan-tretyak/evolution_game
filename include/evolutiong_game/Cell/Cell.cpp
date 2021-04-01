//
// Created by ivantretyak on 25.03.2021.
//

#include "Cell.h"

#include <utility>

Cell::Cell(Coordinate c, Genes g) {
    Cell::c = c;
    Cell::genes = g;
}

CellType Cell::getType() {
    return genes.getType();
}

Cell::Cell() {
    Cell::c = Coordinate();
    Cell::genes = Genes();
}

Coordinate Cell::getCoordinate() {
    return Cell::c;
}

Coordinate Cell::move(SectionType up, SectionType left, SectionType right, SectionType down, unsigned int size) {
    if (Cell::genes.getType() == omniglot) {
        if (up == food_grass) {
            return c.getNewCoordinate(size, Direction::up);
        }
        if (right == food_grass) {
            return c.getNewCoordinate(size, Direction::right);
        }
        if (left == food_grass) {
            return c.getNewCoordinate(size, Direction::left);
        }
        if (down == food_grass) {
            return c.getNewCoordinate(size, Direction::down);
        }
    }

    if (Cell::genes.getType() == predator) {
        if (up == food_meat) {
            return c.getNewCoordinate(size, Direction::up);
        }
        if (right == food_meat) {
            return c.getNewCoordinate(size, Direction::right);
        }
        if (left == food_meat) {
            return c.getNewCoordinate(size, Direction::left);
        }
        if (down == food_meat) {
            return c.getNewCoordinate(size, Direction::down);
        }
    }

    if (up == empty) {
        return c.getNewCoordinate(size, Direction::up);
    }
    if (right == empty) {
        return c.getNewCoordinate(size, Direction::right);
    }
    if (left == empty) {
        return c.getNewCoordinate(size, Direction::left);
    }
    if (down == empty) {
        return c.getNewCoordinate(size, Direction::down);
    }
    return Coordinate({-1, -1});
}

void Cell::changeCoordinate(Coordinate coord) {
    Cell::c = coord;
}

void Cell::eat(int e) {
    Cell::energy = Cell::energy + e;
}

void Cell::switchMoving() {
    moving = !moving;
}

bool Cell::getMoving() const {
    return moving;
}
