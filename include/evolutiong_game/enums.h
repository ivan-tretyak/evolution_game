//
// Created by ivantretyak on 25.03.2021.
//

#ifndef GENES_ENUMS_H
#define GENES_ENUMS_H
#include <string>


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

enum GenesEnum {
    gene_type,
    gene_damage,
    gene_energyForReproduction,
    gene_startEnergy,
    gene_maxAge,
    gene_leftBorderMove,
    gene_rightBorderMove,
    gene_upBorderMove,
    gene_downBorderMove,
    gene_freeDirection,
    gene_freeDirectionSecondary,
    gene_mutantChance
};

std::string getNumeration(CellType t);
std::string getNumeration(Direction t);
#endif //GENES_ENUMS_H
