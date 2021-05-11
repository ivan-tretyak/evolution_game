//
// Created by ivantretyak on 25.03.2021.
//

#include "Cell.h"
#include "Genes.h"

#include <utility>

Cell::Cell(Coordinate c, Genes g) {
    Cell::c = c;
    Cell::genes = g;
    Cell::energy = genes.getStarEnergy();
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

Coordinate Cell::move(SectionType up, SectionType left, SectionType right, SectionType down) {
    age += 1;
    energy = energy - 1;
    if (Cell::energy > Cell::genes.getEnergyForReproduction() && (up == empty || left == empty || right == empty || down == empty)) {
        return c;
    }

    if (Cell::genes.getType() == omniglot) {
        if (up == food_grass) {
            return c.getNewCoordinate(Direction::up);
        }
        if (right == food_grass) {
            return c.getNewCoordinate(Direction::right);
        }
        if (left == food_grass) {
            return c.getNewCoordinate(Direction::left);
        }
        if (down == food_grass) {
            return c.getNewCoordinate(Direction::down);
        }
    }

    if (Cell::genes.getType() == predator) {
        if (up == food_meat) {
            return c.getNewCoordinate(Direction::up);
        }
        if (right == food_meat) {
            return c.getNewCoordinate(Direction::right);
        }
        if (left == food_meat) {
            return c.getNewCoordinate(Direction::left);
        }
        if (down == food_meat) {
            return c.getNewCoordinate(Direction::down);
        }

        if (up == cell_hebivor || up == cell_predator) {
            return c.getNewCoordinate(Direction::up);
        }

        if (right == cell_hebivor || right == cell_predator) {
            return c.getNewCoordinate(Direction::right);
        }

        if (down == cell_hebivor || down == cell_predator) {
            return c.getNewCoordinate(Direction::down);
        }

        if (left == cell_hebivor || left == cell_predator) {
            return c.getNewCoordinate(Direction::left);
        }
    }

    if (up == border){
        switch (Cell::genes.getUpBorderMove()) {
            case Direction::left: {
                if (left == empty) {
                    return c.getNewCoordinate(Direction::left);
                }
            }
            case Direction::right: {
                if (right == empty) {
                    return c.getNewCoordinate(Direction::right);
                }
            }
            case Direction::down: {
                if (down == empty) {
                    return c.getNewCoordinate(Direction::down);
                }
            }
            case Direction::up:
                break;
        }
    }

    if (down == border){
        switch (Cell::genes.getDownBorderMove()) {
            case Direction::left: {
                if (left == empty) {
                    return c.getNewCoordinate(Direction::left);
                }
            }
            case Direction::right: {
                if (right == empty) {
                    return c.getNewCoordinate(Direction::right);
                }
            }
            case Direction::up: {
                if (up == empty) {
                    return c.getNewCoordinate(Direction::up);
                }
            }
            case Direction::down:
                break;
        }
    }

    if (right == border){
        switch (Cell::genes.getRightBorderMove()) {
            case Direction::left: {
                if (left == empty) {
                    return c.getNewCoordinate(Direction::left);
                }
            }
            case Direction::up: {
                if (up == empty) {
                    return c.getNewCoordinate(Direction::up);
                }
            }
            case Direction::down: {
                if (down == empty) {
                    return c.getNewCoordinate(Direction::down);
                }
            }
            case Direction::right:
                break;
        }
    }

    if (left == border){
        switch (Cell::genes.getLeftBorderMove()) {
            case Direction::up: {
                if (up == empty) {
                    return c.getNewCoordinate(Direction::up);
                }
                break;
            }
            case Direction::right: {
                if (right == empty) {
                    return c.getNewCoordinate(Direction::right);
                }
                break;
            }
            case Direction::down: {
                if (down == empty) {
                    return c.getNewCoordinate(Direction::down);
                }
                break;
            }
            case Direction::left:
                break;
        }
    }

    if (Cell::genes.getFreeDirection() == Direction::up && up == empty) {
        return c.getNewCoordinate(Direction::up);
    }

    if (Cell::genes.getFreeDirection() == Direction::down && down == empty) {
        return c.getNewCoordinate(Direction::down);
    }

    if (Cell::genes.getFreeDirection() == Direction::right && right == empty) {
        return c.getNewCoordinate(Direction::right);
    }

    if (Cell::genes.getFreeDirection() == Direction::left && left == empty) {
        return c.getNewCoordinate(Direction::left);
    }

    if (Cell::genes.getFreeDirectionSecondary() == Direction::up && up == empty) {
        return c.getNewCoordinate(Direction::up);
    }

    if (Cell::genes.getFreeDirectionSecondary() == Direction::down && down == empty) {
        return c.getNewCoordinate(Direction::down);
    }

    if (Cell::genes.getFreeDirectionSecondary() == Direction::right && right == empty) {
        return c.getNewCoordinate(Direction::right);
    }

    if (Cell::genes.getFreeDirectionSecondary() == Direction::left && left == empty) {
        return c.getNewCoordinate(Direction::left);
    }

    if (up == empty) {
        return c.getNewCoordinate(Direction::up);
    }
    if (right == empty) {
        return c.getNewCoordinate(Direction::right);
    }
    if (left == empty) {
        return c.getNewCoordinate(Direction::left);
    }
    if (down == empty) {
        return c.getNewCoordinate(Direction::down);
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

bool Cell::death() {
    return genes.getMaxAge() < age || energy < 0;
}

int Cell::getEnergy() {
    return energy;
}

void Cell::hit(int d) {
    Cell::energy -= d;
}

int Cell::damage() {
    return Cell::genes.getDamage();
}

Cell Cell::reproduction(SectionType up, SectionType left, SectionType right, SectionType down) {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<> chance(0, 100);
    std::uniform_int_distribution<> gene(0, 11);
    Genes new_genes = Cell::genes.reproduction(chance(gen), static_cast<GenesEnum>(gene(gen)));
    if (down == empty) {
        return Cell(Coordinate(Cell::c.getNewCoordinate(Direction::down)), new_genes);
    }
    if (right == empty) {
        return Cell(Coordinate(Cell::c.getNewCoordinate(Direction::right)), new_genes);
    }
    if (left == empty) {
        return Cell(Coordinate(Cell::c.getNewCoordinate(Direction::left)), new_genes);
    }
    return Cell(Coordinate(Cell::c.getNewCoordinate(Direction::up)), new_genes);
}

Genes Cell::getGenes() {
    return genes;
}

int Cell::getAge() {
    return age;
}
