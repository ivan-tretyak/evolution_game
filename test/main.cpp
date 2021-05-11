#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include "../include/evolutiong_game/Cell/Coordinate.h"
#include "TestGenes.h"

Coordinate current({5, 5});

NotMutant notMutant;
DownBorderMoveMutant downBorderMoveMutant;
RightBorderMoveMutant rightBorderMoveMutant;
LeftBorderMoveMutant leftBorderMoveMutant;
UpBorderMoveMutant upBorderMoveMutant;
TypeMutant typeMutant;
FreeDirectionMoveMutant freeDirectionMoveMutant;
FreeDirectionSecondaryMoveMutant freeDirectionSecondaryMoveMutant;
DamageMutant damageMutant;
MaxAgeMutant maxAgeMutant;
EnergyForReproductionMutant energyForReproductionMutant;
MutantChanceMutant mutantChanceMutant;
StarEnergyMutant starEnergyMutant;

Genes genesOriginal(up, down, right, left, up, down, predator, 150, 20, 300, 150, 30);

TEST_CASE("Проверка расчета новых координат") {
    CHECK(current.getNewCoordinate(up)[0] == 5);
    CHECK(current.getNewCoordinate(up)[1] == 4);
    CHECK(current.getNewCoordinate(down)[0] == 5);
    CHECK(current.getNewCoordinate(down)[1] == 6);
    CHECK(current.getNewCoordinate(right)[0] == 6);
    CHECK(current.getNewCoordinate(right)[1] == 5);
    CHECK(current.getNewCoordinate(left)[0] == 4);
    CHECK(current.getNewCoordinate(left)[1] == 5);
}

Genes notMutantGene = genesOriginal.reproduction(notMutant.chance(), notMutant.gene());
TEST_CASE("Проверка неизменности генов при отсутствии мутациий.") {
    CHECK(genesOriginal.getDownBorderMove() == notMutantGene.getDownBorderMove());
    CHECK(genesOriginal.getRightBorderMove() == notMutantGene.getRightBorderMove());
    CHECK(genesOriginal.getLeftBorderMove() == notMutantGene.getLeftBorderMove());
    CHECK(genesOriginal.getUpBorderMove() == notMutantGene.getUpBorderMove());
    CHECK(genesOriginal.getFreeDirection() == notMutantGene.getFreeDirection());
    CHECK(genesOriginal.getFreeDirectionSecondary() == notMutantGene.getFreeDirectionSecondary());
    CHECK(genesOriginal.getDamage() == notMutantGene.getDamage());
    CHECK(genesOriginal.getMaxAge() == notMutantGene.getMaxAge());
    CHECK(genesOriginal.getType() == notMutantGene.getType());
    CHECK(genesOriginal.getEnergyForReproduction() == notMutantGene.getEnergyForReproduction());
    CHECK(genesOriginal.getMutantChance() == notMutantGene.getMutantChance());
    CHECK(genesOriginal.getStarEnergy() == notMutantGene.getStarEnergy());
}

Genes downBorderMoveMutantGene = genesOriginal.reproduction(downBorderMoveMutant.chance(), downBorderMoveMutant.gene());
TEST_CASE("Проверка мутации гена движения вдоль нижней границы.") {
    CHECK(genesOriginal.getDownBorderMove() != downBorderMoveMutantGene.getDownBorderMove());
    CHECK(genesOriginal.getRightBorderMove() == downBorderMoveMutantGene.getRightBorderMove());
    CHECK(genesOriginal.getLeftBorderMove() == downBorderMoveMutantGene.getLeftBorderMove());
    CHECK(genesOriginal.getUpBorderMove() == downBorderMoveMutantGene.getUpBorderMove());
    CHECK(genesOriginal.getFreeDirection() == downBorderMoveMutantGene.getFreeDirection());
    CHECK(genesOriginal.getFreeDirectionSecondary() == downBorderMoveMutantGene.getFreeDirectionSecondary());
    CHECK(genesOriginal.getDamage() == downBorderMoveMutantGene.getDamage());
    CHECK(genesOriginal.getMaxAge() == downBorderMoveMutantGene.getMaxAge());
    CHECK(genesOriginal.getType() == downBorderMoveMutantGene.getType());
    CHECK(genesOriginal.getEnergyForReproduction() == downBorderMoveMutantGene.getEnergyForReproduction());
    CHECK(genesOriginal.getMutantChance() == downBorderMoveMutantGene.getMutantChance());
    CHECK(genesOriginal.getStarEnergy() == downBorderMoveMutantGene.getStarEnergy());
}

Genes rightBorderMoveMutantGene = genesOriginal.reproduction(rightBorderMoveMutant.chance(), rightBorderMoveMutant.gene());
TEST_CASE("Проверка мутации гена движения вдоль правой границы.") {
    CHECK(genesOriginal.getDownBorderMove() == rightBorderMoveMutantGene.getDownBorderMove());
    CHECK(genesOriginal.getRightBorderMove() != rightBorderMoveMutantGene.getRightBorderMove());
    CHECK(genesOriginal.getLeftBorderMove() == rightBorderMoveMutantGene.getLeftBorderMove());
    CHECK(genesOriginal.getUpBorderMove() == rightBorderMoveMutantGene.getUpBorderMove());
    CHECK(genesOriginal.getFreeDirection() == rightBorderMoveMutantGene.getFreeDirection());
    CHECK(genesOriginal.getFreeDirectionSecondary() == rightBorderMoveMutantGene.getFreeDirectionSecondary());
    CHECK(genesOriginal.getDamage() == rightBorderMoveMutantGene.getDamage());
    CHECK(genesOriginal.getMaxAge() == rightBorderMoveMutantGene.getMaxAge());
    CHECK(genesOriginal.getType() == rightBorderMoveMutantGene.getType());
    CHECK(genesOriginal.getEnergyForReproduction() == rightBorderMoveMutantGene.getEnergyForReproduction());
    CHECK(genesOriginal.getMutantChance() == rightBorderMoveMutantGene.getMutantChance());
    CHECK(genesOriginal.getStarEnergy() == rightBorderMoveMutantGene.getStarEnergy());
}

Genes leftBorderMoveMutantGene = genesOriginal.reproduction(leftBorderMoveMutant.chance(), leftBorderMoveMutant.gene());
TEST_CASE("Проверка мутации гена движения вдоль левой границы.") {
    CHECK(genesOriginal.getDownBorderMove() == leftBorderMoveMutantGene.getDownBorderMove());
    CHECK(genesOriginal.getRightBorderMove() == leftBorderMoveMutantGene.getRightBorderMove());
    CHECK(genesOriginal.getLeftBorderMove() != leftBorderMoveMutantGene.getLeftBorderMove());
    CHECK(genesOriginal.getUpBorderMove() == leftBorderMoveMutantGene.getUpBorderMove());
    CHECK(genesOriginal.getFreeDirection() == leftBorderMoveMutantGene.getFreeDirection());
    CHECK(genesOriginal.getFreeDirectionSecondary() == leftBorderMoveMutantGene.getFreeDirectionSecondary());
    CHECK(genesOriginal.getDamage() == leftBorderMoveMutantGene.getDamage());
    CHECK(genesOriginal.getMaxAge() == leftBorderMoveMutantGene.getMaxAge());
    CHECK(genesOriginal.getType() == leftBorderMoveMutantGene.getType());
    CHECK(genesOriginal.getEnergyForReproduction() == leftBorderMoveMutantGene.getEnergyForReproduction());
    CHECK(genesOriginal.getMutantChance() == leftBorderMoveMutantGene.getMutantChance());
    CHECK(genesOriginal.getStarEnergy() == leftBorderMoveMutantGene.getStarEnergy());
}

Genes upBorderMoveMutantGene = genesOriginal.reproduction(upBorderMoveMutant.chance(), upBorderMoveMutant.gene());
TEST_CASE("Проверка мутации гена движения вдоль верхней границы.") {
    CHECK(genesOriginal.getDownBorderMove() == upBorderMoveMutantGene.getDownBorderMove());
    CHECK(genesOriginal.getRightBorderMove() == upBorderMoveMutantGene.getRightBorderMove());
    CHECK(genesOriginal.getLeftBorderMove() == upBorderMoveMutantGene.getLeftBorderMove());
    CHECK(genesOriginal.getUpBorderMove() != upBorderMoveMutantGene.getUpBorderMove());
    CHECK(genesOriginal.getFreeDirection() == upBorderMoveMutantGene.getFreeDirection());
    CHECK(genesOriginal.getFreeDirectionSecondary() == upBorderMoveMutantGene.getFreeDirectionSecondary());
    CHECK(genesOriginal.getDamage() == upBorderMoveMutantGene.getDamage());
    CHECK(genesOriginal.getMaxAge() == upBorderMoveMutantGene.getMaxAge());
    CHECK(genesOriginal.getType() == upBorderMoveMutantGene.getType());
    CHECK(genesOriginal.getEnergyForReproduction() == upBorderMoveMutantGene.getEnergyForReproduction());
    CHECK(genesOriginal.getMutantChance() == upBorderMoveMutantGene.getMutantChance());
    CHECK(genesOriginal.getStarEnergy() == upBorderMoveMutantGene.getStarEnergy());
}

Genes freeDirectionMutantGene = genesOriginal.reproduction(freeDirectionMoveMutant.chance(), freeDirectionMoveMutant.gene());
TEST_CASE("Проверка мутации гена главного направления свободного движения.") {
    CHECK(genesOriginal.getDownBorderMove() == freeDirectionMutantGene.getDownBorderMove());
    CHECK(genesOriginal.getRightBorderMove() == freeDirectionMutantGene.getRightBorderMove());
    CHECK(genesOriginal.getLeftBorderMove() == freeDirectionMutantGene.getLeftBorderMove());
    CHECK(genesOriginal.getUpBorderMove() == freeDirectionMutantGene.getUpBorderMove());
    CHECK(genesOriginal.getFreeDirection() != freeDirectionMutantGene.getFreeDirection());
    CHECK(genesOriginal.getFreeDirectionSecondary() == freeDirectionMutantGene.getFreeDirectionSecondary());
    CHECK(genesOriginal.getDamage() == freeDirectionMutantGene.getDamage());
    CHECK(genesOriginal.getMaxAge() == freeDirectionMutantGene.getMaxAge());
    CHECK(genesOriginal.getType() == freeDirectionMutantGene.getType());
    CHECK(genesOriginal.getEnergyForReproduction() == freeDirectionMutantGene.getEnergyForReproduction());
    CHECK(genesOriginal.getMutantChance() == freeDirectionMutantGene.getMutantChance());
    CHECK(genesOriginal.getStarEnergy() == freeDirectionMutantGene.getStarEnergy());
}

Genes freeDirectionSecondaryMutantGene = genesOriginal.reproduction(freeDirectionSecondaryMoveMutant.chance(), freeDirectionSecondaryMoveMutant.gene());
TEST_CASE("Проверка мутации гена другое направления свободного движения.") {
    CHECK(genesOriginal.getDownBorderMove() == freeDirectionSecondaryMutantGene.getDownBorderMove());
    CHECK(genesOriginal.getRightBorderMove() == freeDirectionSecondaryMutantGene.getRightBorderMove());
    CHECK(genesOriginal.getLeftBorderMove() == freeDirectionSecondaryMutantGene.getLeftBorderMove());
    CHECK(genesOriginal.getUpBorderMove() == freeDirectionSecondaryMutantGene.getUpBorderMove());
    CHECK(genesOriginal.getFreeDirection() == freeDirectionSecondaryMutantGene.getFreeDirection());
    CHECK(genesOriginal.getFreeDirectionSecondary() != freeDirectionSecondaryMutantGene.getFreeDirectionSecondary());
    CHECK(genesOriginal.getDamage() == freeDirectionSecondaryMutantGene.getDamage());
    CHECK(genesOriginal.getMaxAge() == freeDirectionSecondaryMutantGene.getMaxAge());
    CHECK(genesOriginal.getType() == freeDirectionSecondaryMutantGene.getType());
    CHECK(genesOriginal.getEnergyForReproduction() == freeDirectionSecondaryMutantGene.getEnergyForReproduction());
    CHECK(genesOriginal.getMutantChance() == freeDirectionSecondaryMutantGene.getMutantChance());
    CHECK(genesOriginal.getStarEnergy() == freeDirectionSecondaryMutantGene.getStarEnergy());
}

Genes damageMutantGene = genesOriginal.reproduction(damageMutant.chance(), damageMutant.gene());
TEST_CASE("Проверка изменения урона."){
    CHECK(genesOriginal.getDownBorderMove() == damageMutantGene.getDownBorderMove());
    CHECK(genesOriginal.getRightBorderMove() == damageMutantGene.getRightBorderMove());
    CHECK(genesOriginal.getLeftBorderMove() == damageMutantGene.getLeftBorderMove());
    CHECK(genesOriginal.getUpBorderMove() == damageMutantGene.getUpBorderMove());
    CHECK(genesOriginal.getFreeDirection() == damageMutantGene.getFreeDirection());
    CHECK(genesOriginal.getFreeDirectionSecondary() == damageMutantGene.getFreeDirectionSecondary());
    CHECK(genesOriginal.getDamage() != damageMutantGene.getDamage());
    CHECK(genesOriginal.getMaxAge() == damageMutantGene.getMaxAge());
    CHECK(genesOriginal.getType() == damageMutantGene.getType());
    CHECK(genesOriginal.getEnergyForReproduction() == damageMutantGene.getEnergyForReproduction());
    CHECK(genesOriginal.getMutantChance() == damageMutantGene.getMutantChance());
    CHECK(genesOriginal.getStarEnergy() == damageMutantGene.getStarEnergy());
}

Genes maxAgeMutantGene = genesOriginal.reproduction(maxAgeMutant.chance(), maxAgeMutant.gene());
TEST_CASE("Проверка изменения максимального возраста."){
    CHECK(genesOriginal.getDownBorderMove() == maxAgeMutantGene.getDownBorderMove());
    CHECK(genesOriginal.getRightBorderMove() == maxAgeMutantGene.getRightBorderMove());
    CHECK(genesOriginal.getLeftBorderMove() == maxAgeMutantGene.getLeftBorderMove());
    CHECK(genesOriginal.getUpBorderMove() == maxAgeMutantGene.getUpBorderMove());
    CHECK(genesOriginal.getFreeDirection() == maxAgeMutantGene.getFreeDirection());
    CHECK(genesOriginal.getFreeDirectionSecondary() == maxAgeMutantGene.getFreeDirectionSecondary());
    CHECK(genesOriginal.getDamage() == maxAgeMutantGene.getDamage());
    CHECK(genesOriginal.getMaxAge() != maxAgeMutantGene.getMaxAge());
    CHECK(genesOriginal.getType() == maxAgeMutantGene.getType());
    CHECK(genesOriginal.getEnergyForReproduction() == maxAgeMutantGene.getEnergyForReproduction());
    CHECK(genesOriginal.getMutantChance() == maxAgeMutantGene.getMutantChance());
    CHECK(genesOriginal.getStarEnergy() == maxAgeMutantGene.getStarEnergy());
}

Genes typeMutantGene = genesOriginal.reproduction(typeMutant.chance(), typeMutant.gene());
TEST_CASE("Проверка мутации типа") {
    CHECK(genesOriginal.getDownBorderMove() == typeMutantGene.getDownBorderMove());
    CHECK(genesOriginal.getRightBorderMove() == typeMutantGene.getRightBorderMove());
    CHECK(genesOriginal.getLeftBorderMove() == typeMutantGene.getLeftBorderMove());
    CHECK(genesOriginal.getUpBorderMove() == typeMutantGene.getUpBorderMove());
    CHECK(genesOriginal.getFreeDirection() == typeMutantGene.getFreeDirection());
    CHECK(genesOriginal.getFreeDirectionSecondary() == typeMutantGene.getFreeDirectionSecondary());
    CHECK(genesOriginal.getDamage() == typeMutantGene.getDamage());
    CHECK(genesOriginal.getMaxAge() == typeMutantGene.getMaxAge());
    CHECK(genesOriginal.getType() != typeMutantGene.getType());
    CHECK(genesOriginal.getEnergyForReproduction() == typeMutantGene.getEnergyForReproduction());
    CHECK(genesOriginal.getMutantChance() == typeMutantGene.getMutantChance());
    CHECK(genesOriginal.getStarEnergy() == typeMutantGene.getStarEnergy());
}

Genes energyForReproductionMutantGene = genesOriginal.reproduction(energyForReproductionMutant.chance(), energyForReproductionMutant.gene());
TEST_CASE("Проверка изменения мутации энергии для размножения."){
    CHECK(genesOriginal.getDownBorderMove() == energyForReproductionMutantGene.getDownBorderMove());
    CHECK(genesOriginal.getRightBorderMove() == energyForReproductionMutantGene.getRightBorderMove());
    CHECK(genesOriginal.getLeftBorderMove() == energyForReproductionMutantGene.getLeftBorderMove());
    CHECK(genesOriginal.getUpBorderMove() == energyForReproductionMutantGene.getUpBorderMove());
    CHECK(genesOriginal.getFreeDirection() == energyForReproductionMutantGene.getFreeDirection());
    CHECK(genesOriginal.getFreeDirectionSecondary() == energyForReproductionMutantGene.getFreeDirectionSecondary());
    CHECK(genesOriginal.getDamage() == energyForReproductionMutantGene.getDamage());
    CHECK(genesOriginal.getMaxAge() == energyForReproductionMutantGene.getMaxAge());
    CHECK(genesOriginal.getType() == energyForReproductionMutantGene.getType());
    CHECK(genesOriginal.getEnergyForReproduction() != energyForReproductionMutantGene.getEnergyForReproduction());
    CHECK(genesOriginal.getMutantChance() == energyForReproductionMutantGene.getMutantChance());
    CHECK(genesOriginal.getStarEnergy() != energyForReproductionMutantGene.getStarEnergy());
}

Genes mutantChanceMutantGene = genesOriginal.reproduction(mutantChanceMutant.chance(), mutantChanceMutant.gene());
TEST_CASE("Проверка изменения шанса мутации."){
    CHECK(genesOriginal.getDownBorderMove() == mutantChanceMutantGene.getDownBorderMove());
    CHECK(genesOriginal.getRightBorderMove() == mutantChanceMutantGene.getRightBorderMove());
    CHECK(genesOriginal.getLeftBorderMove() == mutantChanceMutantGene.getLeftBorderMove());
    CHECK(genesOriginal.getUpBorderMove() == mutantChanceMutantGene.getUpBorderMove());
    CHECK(genesOriginal.getFreeDirection() == mutantChanceMutantGene.getFreeDirection());
    CHECK(genesOriginal.getFreeDirectionSecondary() == mutantChanceMutantGene.getFreeDirectionSecondary());
    CHECK(genesOriginal.getDamage() == mutantChanceMutantGene.getDamage());
    CHECK(genesOriginal.getMaxAge() == mutantChanceMutantGene.getMaxAge());
    CHECK(genesOriginal.getType() == mutantChanceMutantGene.getType());
    CHECK(genesOriginal.getEnergyForReproduction() == mutantChanceMutantGene.getEnergyForReproduction());
    CHECK(genesOriginal.getMutantChance() != mutantChanceMutantGene.getMutantChance());
    CHECK(genesOriginal.getStarEnergy() == mutantChanceMutantGene.getStarEnergy());
}


