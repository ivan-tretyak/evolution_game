//
// Created by ivantretyak on 25.04.2021.
//

#ifndef GENES_TESTGENES_H
#define GENES_TESTGENES_H
#include "../include/evolutiong_game/Cell/Genes.h"


class IRandom {
public:
    virtual int chance() = 0;

    virtual GenesEnum gene() = 0;
};

class NotMutant : public IRandom {

public:
    int chance();

    GenesEnum gene();
};

class TypeMutant : public IRandom {
public:
    int chance();

    GenesEnum gene();
};

class DownBorderMoveMutant : public IRandom {
public:
    int chance();

    GenesEnum gene();
};

class RightBorderMoveMutant : public IRandom {
public:
    int chance();

    GenesEnum gene();
};

class LeftBorderMoveMutant : public IRandom {
public:
    int chance();

    GenesEnum gene();
};

class UpBorderMoveMutant : public IRandom {
public:
    int chance();

    GenesEnum gene();
};

class FreeDirectionMoveMutant : public IRandom {
public:
    int chance();

    GenesEnum gene();

};

class FreeDirectionSecondaryMoveMutant : public IRandom {
public:
    int chance();

    GenesEnum gene();
};

class DamageMutant : public IRandom {
public:
    int chance();

    GenesEnum gene();
};

class MaxAgeMutant : public IRandom {
public:
    int chance();

    GenesEnum gene();
};

class EnergyForReproductionMutant : public IRandom {
public:
    int chance();

    GenesEnum gene();
};

class MutantChanceMutant : public IRandom {
public:
    int chance();

    GenesEnum gene();
};

class StarEnergyMutant : public IRandom {
public:
    int chance();

    GenesEnum gene();
};
#endif //GENES_TESTGENES_H
