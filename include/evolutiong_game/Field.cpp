//
// Created by ivantretyak on 25.03.2021.
//

#include "Field.h"

Field::Field(unsigned int s) {
    Field::size = s;

    Genes g1;
    Genes g;
    do {
        g = Genes();
        g1 = Genes();
    } while (g.getType() == g1.getType());


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
                    if (genes(rs) == 0){
                        Cell c(Coordinate({x, y}), g);
                        section.changeSection(c);
                    } else {
                        Cell c(Coordinate({x, y}), g1);
                        section.changeSection(c);
                    }
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


void Field::show() {
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            switch (Field::field[y][x].getType()) {
                case empty:
                    std::cout << "[ ]";
                    break;
                case cell_predator:
                    std::cout << "[p]";
                    break;
                case cell_hebivor:
                    std::cout << "[h]";
                    break;
                case food_grass:
                    std::cout << "[g]";
                    break;
                case food_meat:
                    std::cout << "[m]";
                    break;
                case border:
                    std::cout << "[:]";
            }
        }
        std::cout << std::endl;
    }
}

void Field::move() {
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            switch (field[y][x].getType()) {
                case cell_hebivor:
                case cell_predator: {
                    if (std::get<Cell>(field[y][x].getItem()).death()) {
                        field[y][x].changeSection(Food(meat, std::get<Cell>(field[y][x].getItem()).getEnergy()));
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
                            std::get<Cell>(field[newXY[1]][newXY[0]].getItem()).hit(std::get<Cell>(field[y][x].getItem()).damage());
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
