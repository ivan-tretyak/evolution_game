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

    if (up == border){
        switch (Cell::genes.getUpBorderMove()) {
            case Direction::left: {
                if (left == empty) {
                    return c.getNewCoordinate(size, Direction::left);
                }
            }
            case Direction::right: {
                if (right == empty) {
                    return c.getNewCoordinate(size, Direction::right);
                }
            }
            case Direction::down: {
                if (down == empty) {
                    return c.getNewCoordinate(size, Direction::down);
                }
            }
            case Direction::up:
                break;
        }
    }

    if (down == border){
        switch (Cell::genes.getUpBorderMove()) {
            case Direction::left: {
                if (left == empty) {
                    return c.getNewCoordinate(size, Direction::left);
                }
            }
            case Direction::right: {
                if (right == empty) {
                    return c.getNewCoordinate(size, Direction::right);
                }
            }
            case Direction::up: {
                if (up == empty) {
                    return c.getNewCoordinate(size, Direction::up);
                }
            }
            case Direction::down:
                break;
        }
    }

    if (right == border){
        switch (Cell::genes.getUpBorderMove()) {
            case Direction::left: {
                if (left == empty) {
                    return c.getNewCoordinate(size, Direction::left);
                }
            }
            case Direction::up: {
                if (up == empty) {
                    return c.getNewCoordinate(size, Direction::up);
                }
            }
            case Direction::down: {
                if (down == empty) {
                    return c.getNewCoordinate(size, Direction::down);
                }
            }
            case ::right:
                break;
        }
    }

    if (left == border){
        switch (Cell::genes.getUpBorderMove()) {
            case Direction::up: {
                if (up == empty) {
                    return c.getNewCoordinate(size, Direction::up);
                }
                break;
            }
            case Direction::right: {
                if (right == empty) {
                    return c.getNewCoordinate(size, Direction::right);
                }
                break;
            }
            case Direction::down: {
                if (down == empty) {
                    return c.getNewCoordinate(size, Direction::down);
                }
                break;
            }
            case Direction::left:
                break;
        }
    }

    if (Cell::genes.getFreeDirection() == Direction::up && up == empty) {
        return c.getNewCoordinate(size, Direction::up);
    }

    if (Cell::genes.getFreeDirection() == Direction::down && down == empty) {
        return c.getNewCoordinate(size, Direction::down);
    }

    if (Cell::genes.getFreeDirection() == Direction::right && right == empty) {
        return c.getNewCoordinate(size, Direction::right);
    }

    if (Cell::genes.getFreeDirection() == Direction::left && left == empty) {
        return c.getNewCoordinate(size, Direction::left);
    }

    if (Cell::genes.getFreeDirectionSecondary() == Direction::up && up == empty) {
        return c.getNewCoordinate(size, Direction::up);
    }

    if (Cell::genes.getFreeDirectionSecondary() == Direction::down && down == empty) {
        return c.getNewCoordinate(size, Direction::down);
    }

    if (Cell::genes.getFreeDirectionSecondary() == Direction::right && right == empty) {
        return c.getNewCoordinate(size, Direction::right);
    }

    if (Cell::genes.getFreeDirectionSecondary() == Direction::left && left == empty) {
        return c.getNewCoordinate(size, Direction::left);
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
    age += 1;
    energy = energy - 1;
}

bool Cell::getMoving() const {
    return moving;
}

bool Cell::death() {
    return genes.getMaxAge() < age || energy < 0;
}

int Cell::getEnergy() {
    return energy;
}
