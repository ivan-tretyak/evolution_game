//
// Created by ivantretyak on 30.03.2021.
//

#ifndef GENES_GENES_H
#define GENES_GENES_H

#include "../enums.h"
#include <random>

class Genes {
private:
    Direction leftBorderMove;
    Direction rightBorderMove;
    Direction upBorderMove;
    Direction downBoderMove;
    Direction FreeDirection;

    Direction FreeDirectionSecondary;

    CellType type;
    int maxAge;
    int damage;
    int energyForReproduction;
    int startEnergy;
public:
    Genes();
    Direction getLeftBorderMove();
    Direction getRightBorderMove();
    Direction getUpBorderMove();
    Direction getDownBorderMove();
    Direction getFreeDirection();
    Direction getFreeDirectionSecondary();
    int getMaxAge();
    int getDamage();
    int getEnergyForReproduction();
    CellType getType();
};


#endif //GENES_GENES_H
