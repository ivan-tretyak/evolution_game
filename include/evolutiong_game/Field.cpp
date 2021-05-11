//
// Created by ivantretyak on 25.03.2021.
//

#include "Field.h"

Field::Field(unsigned int s) {
    Field::size = s;

    for (int y = 0; y < Field::size; y++) {
        std::vector<Section> temp;
        for (int x = 0; x < Field::size; x++) {
            Section section;
            if (x == 0 || x == size - 1 || y == 0 || y == size - 1) {
                section.setBorder();
                temp.push_back(section);
            } else {
                std::random_device rs;
                std::uniform_int_distribution<> types(0, 100);
                std::uniform_int_distribution<> genes(0, 1);
                int t = types(rs);
                if (t < 10) {
                    Cell c(Coordinate({x, y}), Genes());
                    section.changeSection(c);
                }
                if (t > 10 && t < 20) {
                    Food f(grass, 25);
                    section.changeSection(f);
                }
                temp.push_back(section);
            }
        }
        Field::field.push_back(temp);
    }
}

void Field::move() {
    steps++;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            switch (field[y][x].getType()) {
                case cell_hebivor:
                case cell_predator: {
                    Cell *cell = &std::get<Cell>(field[y][x].getItem());
                    if (cell->death()) {
                        field[y][x].changeSection(Food(meat, 100));
                        break;
                    }
                    if (cell->getMoving()) {
                        break;
                    }
                    cell->switchMoving();
                    Coordinate currentCoordinate = cell->getCoordinate();
                    SectionType upT;
                    SectionType downT;
                    SectionType rightT;
                    SectionType leftT;
                    getAround(currentCoordinate, upT, downT, rightT, leftT);
                    Coordinate newCoordinate = cell->move(upT, leftT, rightT, downT);
                    if (newCoordinate.getXY()[0] == -1 && newCoordinate.getXY()[1] == -1) {
                        break;
                    }

                    if (newCoordinate.getXY()[0] == x && newCoordinate.getXY()[1] == y) {
                        Cell newCell = cell->reproduction(upT, leftT, rightT, downT);
                        auto xy = newCell.getCoordinate().getXY();
                        field[xy[1]][xy[0]].changeSection(newCell);
                        break;
                    }

                    std::vector<int> newXY = newCoordinate.getXY();
                    switch (field[newXY[1]][newXY[0]].getType()) {
                        case empty: {
                            moving(y, x, newCoordinate, newXY);
                            break;
                        }
                        case food_grass:
                        case food_meat:
                            eating(y, x, newXY);
                            moving(y, x, newCoordinate, newXY);
                            break;

                        case cell_hebivor:
                        case cell_predator:
                            hiting(y, x, newXY);
                            break;
                    }
                }
                case food_meat:
                case food_grass:
                    break;
                case empty: {
                    createFood(y, x);
                    break;
                }

                case border:
                    break;
            }
        }
    }
    switchingMoving();
}

void Field::switchingMoving() {
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (field[y][x].getType() == cell_predator || field[y][x].getType() == cell_hebivor) {
                std::get<Cell>(field[y][x].getItem()).switchMoving();
            }
        }
    }
}

void Field::getAround(Coordinate &currentCoordinate, SectionType &upT, SectionType &downT, SectionType &rightT,
                      SectionType &leftT) {
    std::vector<int> downC = currentCoordinate.getNewCoordinate(down);
    std::vector<int> rightC = currentCoordinate.getNewCoordinate(right);
    std::vector<int> leftC = currentCoordinate.getNewCoordinate(left);
    std::vector<int> upC = currentCoordinate.getNewCoordinate(up);

    upT= field[upC[1]][upC[0]].getType();
    downT= field[downC[1]][downC[0]].getType();
    rightT= field[rightC[1]][rightC[0]].getType();
    leftT= field[leftC[1]][leftC[0]].getType();
}

void Field::createFood(int y, int x) {
    std::random_device rs;
    std::uniform_int_distribution<> types(0, 100);
    int chance = types(rs);
    if (chance < 5) {
        field[y][x].changeSection(Food(grass, 25));
    }
}

void Field::hiting(int y, int x, const std::vector<int> &newXY) {
    std::get<Cell>(field[newXY[1]][newXY[0]].getItem()).hit(
            std::get<Cell>(field[y][x].getItem()).damage());
}

void Field::eating(int y, int x, const std::vector<int> &newXY) {
    std::get<Cell>(field[y][x].getItem()).eat(
            std::get<Food>(field[newXY[1]][newXY[0]].getItem()).getEnergy());
}

void Field::moving(int y, int x, Coordinate &newCoordinate, const std::vector<int> &newXY) {
    field[newXY[1]][newXY[0]].changeSection(std::get<Cell>(field[y][x].getItem()));
    std::get<Cell>(field[newXY[1]][newXY[0]].getItem()).changeCoordinate(newCoordinate);
    field[y][x].erase();
}

long int Field::getSteps() const {
    return steps;
}

std::vector<std::vector<Section>> Field::getField() {
    return field;
}
