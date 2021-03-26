//
// Created by ivantretyak on 25.03.2021.
//

#include "Cell.h"

#include <utility>

Cell::Cell(Coordinate c) {
    Cell::c = c;
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

Coordinate Cell::getCoordinate() {
    return Cell::c;
}

Coordinate Cell::move(SectionType up, SectionType left, SectionType right, SectionType down, unsigned int size) {
    if (Cell::type == omniglot) {
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

    if (Cell::type == predator) {
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
