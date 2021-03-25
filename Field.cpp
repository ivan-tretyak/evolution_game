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
