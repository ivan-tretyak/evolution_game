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

    int mutantChance;
public:
    Genes();
    Genes(Direction lbm,
          Direction rbm,
          Direction ubm,
          Direction dbm,
          Direction fd,
          Direction fds,
          CellType type,
          int mA,
          int d,
          int efr,
          int se,
          int mc);
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
    int getMutantChance();
    Genes reproduction(int chance, GenesEnum gene);
    int getStarEnergy();
};


#endif //GENES_GENES_H
