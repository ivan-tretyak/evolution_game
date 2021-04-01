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
