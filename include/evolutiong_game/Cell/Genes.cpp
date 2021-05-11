//
// Created by ivantretyak on 30.03.2021.
//

#include "Genes.h"

Genes::Genes() {
    std::random_device rd;
    std::mt19937_64 gen(rd());

    std::uniform_int_distribution<> FD(0, 3);
    std::uniform_int_distribution<> TC(0, 1);
    std::uniform_int_distribution<> DAMAGE(15, 30);
    std::uniform_int_distribution<> SE(100, 200);
    std::uniform_int_distribution<> MA(100, 150);
    std::uniform_int_distribution<> MC(0, 100);

    Genes::FreeDirection = static_cast<Direction>(FD(gen));

    do {
        Genes::FreeDirectionSecondary = static_cast<Direction>(FD(gen));
    } while (Genes::FreeDirection == Genes::FreeDirectionSecondary);

    do {
        Genes::leftBorderMove = static_cast<Direction>(FD(gen));
    } while (Genes::leftBorderMove == left);

    do {
        Genes::rightBorderMove = static_cast<Direction>(FD(gen));
    } while (Genes::rightBorderMove == right);

    do {
        Genes::upBorderMove = static_cast<Direction>(FD(gen));
    } while (Genes::upBorderMove == up);

    do {
        Genes::downBoderMove = static_cast<Direction>(FD(gen));
    } while (Genes::downBoderMove == down);

    Genes::type = static_cast<CellType>(TC(gen));
    Genes::damage = DAMAGE(gen);
    Genes::startEnergy = SE(gen);
    Genes::energyForReproduction = startEnergy * 2;
    Genes::maxAge = MA(gen);

    Genes::mutantChance = MC(gen);
}

Direction Genes::getLeftBorderMove() {
    return leftBorderMove;
}

Direction Genes::getDownBorderMove() {
    return downBoderMove;
}

Direction Genes::getFreeDirection() {
    return FreeDirection;
}

Direction Genes::getFreeDirectionSecondary() {
    return FreeDirectionSecondary;
}

Direction Genes::getUpBorderMove() {
    return upBorderMove;
}

Direction Genes::getRightBorderMove() {
    return rightBorderMove;
}

int Genes::getDamage() {
    return damage;
}

int Genes::getMaxAge() {
    return maxAge;
}

int Genes::getEnergyForReproduction() {
    return energyForReproduction;
}

CellType Genes::getType() {
    return type;
}

int Genes::getMutantChance() {
    return mutantChance;
}

Genes::Genes(Direction lbm, Direction rbm, Direction ubm, Direction dbm, Direction fd, Direction fds, CellType type,
             int mA, int d, int efr, int se, int mc) {
    Genes::leftBorderMove = lbm;
    Genes::rightBorderMove = rbm;
    Genes::upBorderMove = ubm;
    Genes::downBoderMove = dbm;
    Genes::FreeDirection = fd;

    Genes::FreeDirectionSecondary = fds;

    Genes::type = type;
    Genes::maxAge = mA;
    Genes::damage = d;
    Genes::energyForReproduction = efr;
    Genes::startEnergy = se;
    Genes::mutantChance = mc;
}

Genes Genes::reproduction(int chance, GenesEnum gene) {
    std::random_device rd;
    std::mt19937_64 gen(rd());

    std::uniform_int_distribution<> FD(0, 3);
    std::uniform_int_distribution<> TC(0, 1);
    std::uniform_int_distribution<> DAMAGE(15, 30);
    std::uniform_int_distribution<> SE(100, 200);
    std::uniform_int_distribution<> MA(100, 150);
    std::uniform_int_distribution<> MC(0, 100);

    Direction new_leftBorderMove = Genes::leftBorderMove;
    Direction new_rightBorderMove = Genes::rightBorderMove;
    Direction new_upBorderMove = Genes::upBorderMove;
    Direction new_downBorderMove = Genes::downBoderMove;

    Direction new_freeDirection = Genes::FreeDirection;
    Direction new_freeDirectionSecondary = Genes::FreeDirectionSecondary;

    CellType new_cellType = Genes::type;

    int new_maxAge = Genes::maxAge;
    int new_damage = Genes::damage;
    int new_energyForReproduction = Genes::energyForReproduction;
    int new_startEnergy = Genes::startEnergy;
    int new_mutantChance = Genes::mutantChance;

    if (chance < mutantChance) {
        switch (gene) {
            case gene_damage: {
                do {
                    new_damage = DAMAGE(gen);
                } while (new_damage == Genes::damage);
                break;
            }
            case gene_downBorderMove: {
                do {
                    new_downBorderMove = static_cast<Direction>(FD(gen));
                } while (new_downBorderMove == down || new_downBorderMove == Genes::downBoderMove);
                break;
            }
            case gene_energyForReproduction:
            case gene_startEnergy: {
                do {
                    new_startEnergy = SE(gen);
                } while (new_startEnergy == Genes::startEnergy);
                new_energyForReproduction = new_startEnergy * 2;
                break;
            }
            case gene_freeDirection: {
                do {
                    new_freeDirection = static_cast<Direction>(FD(gen));
                } while (new_freeDirection == Genes::FreeDirection);
                break;
            }
            case gene_freeDirectionSecondary: {
                do {
                    new_freeDirectionSecondary = static_cast<Direction>(FD(gen));
                } while (new_freeDirectionSecondary == Genes::FreeDirectionSecondary);
                break;
            }
            case gene_leftBorderMove: {
                do {
                    new_leftBorderMove = static_cast<Direction>(FD(gen));
                } while (new_leftBorderMove == left || new_leftBorderMove == Genes::leftBorderMove);
                break;
            }
            case gene_maxAge: {
                do {
                    new_maxAge = MA(gen);
                } while (new_maxAge == Genes::maxAge);
                break;
            }
            case gene_mutantChance: {
                do {
                    new_mutantChance = MC(gen);
                } while (new_mutantChance == Genes::mutantChance);
                break;
            }
            case gene_rightBorderMove: {
                do {
                    new_rightBorderMove = static_cast<Direction>(FD(gen));
                } while (new_rightBorderMove == Genes::rightBorderMove || new_rightBorderMove == right);
                break;
            }
            case gene_type: {
                do {
                    new_cellType = static_cast<CellType>(TC(gen));
                } while (new_cellType == Genes::type);
                break;
            }
            case gene_upBorderMove: {
                do {
                    new_upBorderMove = static_cast<Direction>(FD(gen));
                } while (new_upBorderMove == up || new_upBorderMove == Genes::upBorderMove);
                break;
            }
        }
    }
    return Genes(new_leftBorderMove,
                 new_rightBorderMove,
                 new_upBorderMove,
                 new_downBorderMove,
                 new_freeDirection,
                 new_freeDirectionSecondary,
                 new_cellType,
                 new_maxAge,
                 new_damage,
                 new_energyForReproduction,
                 new_startEnergy,
                 new_mutantChance);
}

int Genes::getStarEnergy() {
    return startEnergy;
}
