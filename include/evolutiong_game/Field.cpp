//
// Created by ivantretyak on 25.03.2021.
//

#include "Field.h"

Field::Field(unsigned int s) {
    Field::size = s;

    for (int y = 0; y < Field::size; y++) {
        std::vector<Section> temp;
        for (int x = 0; x < Field::size; x++) {
            std::random_device rs;
            std::uniform_int_distribution<> types(0, 100);
            Section section;
            int t = types(rs);
            if (t < 10) {
                Cell c(Coordinate({x, y}));
                section.changeSection(c);
            }
            if (t > 10 && t < 20) {
                Food f(grass, 25);
                section.changeSection(f);
            }
            temp.push_back(section);
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
            }
            //std::cout << " " << x << " " << field[y][x].getType() << std::endl;
        }
        std::cout << std::endl;
    }
}

void Field::move() {
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            std::cout << "Section this coordinate(" << x << "," << y << ") have a type: ";
            switch (field[y][x].getType()) {
                case cell_hebivor:
                case cell_predator: {
                    std::cout << "cell\n";
                    Coordinate currentCoordinate = std::get<Cell>(field[y][x].getItem()).getCoordinate();
                    std::vector<int> upC = currentCoordinate.getNewCoordinate(size, up);
                    std::vector<int> downC = currentCoordinate.getNewCoordinate(size, down);
                    std::vector<int> rightC = currentCoordinate.getNewCoordinate(size, right);
                    std::vector<int> leftC = currentCoordinate.getNewCoordinate(size, left);

                    SectionType upT = field[upC[1]][upC[0]].getType();
                    SectionType downT = field[downC[1]][downC[0]].getType();
                    SectionType rightT = field[rightC[1]][rightC[0]].getType();
                    SectionType leftT = field[rightC[1]][rightC[0]].getType();

                    Coordinate newCoordinate = std::get<Cell>(field[y][x].getItem()).move(upT, leftT, rightT, downT, size);\
                    std::cout << "Change coordinate: ";
                    if (newCoordinate.getXY()[0] == -1 && newCoordinate.getXY()[1] == -1) {
                        std::cout << "(-1,-1)\n";
                        break;
                    }

                    std::vector<int> newXY = newCoordinate.getXY();
                    std::cout << "(" << x << "," << y << ") => (" << newXY[0] << "," << newXY[1] <<")\n" << std::endl;

                    field[newXY[1]][newXY[0]].changeSection(std::get<Cell>(field[y][x].getItem()));
                    std::get<Cell>(field[newXY[1]][newXY[0]].getItem()).changeCoordinate(newCoordinate);
                    field[y][x].erase();
                    break;
                }
                case food_meat:
                case food_grass:
                    std::cout << "food\n";
                    break;
                case empty:
                    std::cout << "empty\n";
                    break;
            }
        }
    }
}
