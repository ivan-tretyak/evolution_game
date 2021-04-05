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
                    if (std::get<Cell>(field[y][x].getItem()).death()) {
                        field[y][x].changeSection(Food(meat, 100));
                        break;
                    }
                    if (std::get<Cell>(field[y][x].getItem()).getMoving()) {
                        break;
                    }
                    std::get<Cell>(field[y][x].getItem()).switchMoving();
                    Coordinate currentCoordinate = std::get<Cell>(field[y][x].getItem()).getCoordinate();
                    std::vector<int> upC = currentCoordinate.getNewCoordinate(size, up);
                    std::vector<int> downC = currentCoordinate.getNewCoordinate(size, down);
                    std::vector<int> rightC = currentCoordinate.getNewCoordinate(size, right);
                    std::vector<int> leftC = currentCoordinate.getNewCoordinate(size, left);

                    SectionType upT = field[upC[1]][upC[0]].getType();
                    SectionType downT = field[downC[1]][downC[0]].getType();
                    SectionType rightT = field[rightC[1]][rightC[0]].getType();
                    SectionType leftT = field[leftC[1]][leftC[0]].getType();

                    Coordinate newCoordinate = std::get<Cell>(field[y][x].getItem()).move(upT, leftT, rightT, downT,
                                                                                          size);\
                    if (newCoordinate.getXY()[0] == -1 && newCoordinate.getXY()[1] == -1) {
                        break;
                    }

                    if (newCoordinate.getXY()[0] == x && newCoordinate.getXY()[1] == y) {
                        Cell newCell = std::get<Cell>(field[y][x].getItem()).reproduction(upT, leftT, rightT, downT,
                                                                                          size);
                        auto xy = newCell.getCoordinate().getXY();
                        field[xy[1]][xy[0]].changeSection(newCell);
                        break;
                    }

                    std::vector<int> newXY = newCoordinate.getXY();
                    switch (field[newXY[1]][newXY[0]].getType()) {
                        case empty: {
                            field[newXY[1]][newXY[0]].changeSection(std::get<Cell>(field[y][x].getItem()));
                            std::get<Cell>(field[newXY[1]][newXY[0]].getItem()).changeCoordinate(newCoordinate);
                            field[y][x].erase();
                            break;
                        }
                        case food_grass: {
                            std::get<Cell>(field[y][x].getItem()).eat(
                                    std::get<Food>(field[newXY[1]][newXY[0]].getItem()).getEnergy());
                            field[newXY[1]][newXY[0]].changeSection(std::get<Cell>(field[y][x].getItem()));
                            std::get<Cell>(field[newXY[1]][newXY[0]].getItem()).changeCoordinate(newCoordinate);
                            field[y][x].erase();
                            break;
                        }
                        case food_meat: {
                            std::get<Cell>(field[y][x].getItem()).eat(
                                    std::get<Food>(field[newXY[1]][newXY[0]].getItem()).getEnergy());
                            field[newXY[1]][newXY[0]].changeSection(std::get<Cell>(field[y][x].getItem()));
                            std::get<Cell>(field[newXY[1]][newXY[0]].getItem()).changeCoordinate(newCoordinate);
                            field[y][x].erase();
                            break;
                        }
                        case cell_hebivor:
                        case cell_predator:
                            std::get<Cell>(field[newXY[1]][newXY[0]].getItem()).hit(
                                    std::get<Cell>(field[y][x].getItem()).damage());
                            break;
                    }
                }
                case food_meat:
                case food_grass:
                    break;
                case empty: {
                    std::random_device rs;
                    std::uniform_int_distribution<> types(0, 100);
                    int chance = types(rs);
                    if (chance < 5) {
                        field[y][x].changeSection(Food(grass, 25));
                    }
                    break;
                }

                case border:
                    break;
            }
        }
    }
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (field[y][x].getType() == cell_predator or field[y][x].getType() == cell_hebivor) {
                std::get<Cell>(field[y][x].getItem()).switchMoving();
            }
        }
    }
}

The show and info methods have been removed

The show and info methods are removed from the Field class because they are auxiliary methods and are not directly
related to this part of the application, as they represent elements of the user interface.
