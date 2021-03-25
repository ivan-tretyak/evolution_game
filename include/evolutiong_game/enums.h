//
// Created by ivantretyak on 25.03.2021.
//

#ifndef GENES_ENUMS_H
#define GENES_ENUMS_H

enum FoodType {
    grass,
    meat
};

enum Direction {
    up,
    right,
    down,
    left
};

enum CellType {
    predator,
    omniglot
};

enum SectionType {
    cell_predator,
    cell_hebivor,
    food_grass,
    food_meat,
    empty,
    border
};

#endif //GENES_ENUMS_H
