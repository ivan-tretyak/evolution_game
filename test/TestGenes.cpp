//
// Created by ivantretyak on 25.04.2021.
//

#include "TestGenes.h"

int NotMutant::chance() {
    return 45;
}

GenesEnum NotMutant::gene() {
    return gene_type;
}

int TypeMutant::chance() {
    return 24;
}

GenesEnum TypeMutant::gene() {
    return gene_type;
}

GenesEnum DownBorderMoveMutant::gene() {
    return gene_downBorderMove;
}

int DownBorderMoveMutant::chance() {
    return 24;
}

int RightBorderMoveMutant::chance() {
    return 24;
}

GenesEnum RightBorderMoveMutant::gene() {
    return gene_rightBorderMove;
}

GenesEnum LeftBorderMoveMutant::gene() {
    return gene_leftBorderMove;
}

int LeftBorderMoveMutant::chance() {
    return 24;
}

int UpBorderMoveMutant::chance() {
    return 24;
}

GenesEnum UpBorderMoveMutant::gene() {
    return gene_upBorderMove;
}

int FreeDirectionMoveMutant::chance() {
    return 24;
}

GenesEnum FreeDirectionMoveMutant::gene() {
    return gene_freeDirection;
}

int FreeDirectionSecondaryMoveMutant::chance() {
    return 24;
}

GenesEnum FreeDirectionSecondaryMoveMutant::gene() {
    return gene_freeDirectionSecondary;
}

int DamageMutant::chance() {
    return 15;
}

GenesEnum DamageMutant::gene() {
    return gene_damage;
}

int MaxAgeMutant::chance() {
    return 23;
}

GenesEnum MaxAgeMutant::gene() {
    return gene_maxAge;
}

int EnergyForReproductionMutant::chance() {
    return 12;
}

GenesEnum EnergyForReproductionMutant::gene() {
    return gene_energyForReproduction;
}

int MutantChanceMutant::chance() {
    return 12;
}

GenesEnum MutantChanceMutant::gene() {
    return gene_mutantChance;
}

int StarEnergyMutant::chance() {
    return 13;
}

GenesEnum StarEnergyMutant::gene() {
    return gene_startEnergy;
}
