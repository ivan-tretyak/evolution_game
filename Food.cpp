//
// Created by ivantretyak on 25.03.2021.
//

#include "Food.h"

Food::Food(FoodType t, int e) {
    Food::type = t;
    Food::energy = e;
}

int Food::getEnergy() {
    return energy;
}

FoodType Food::getType() {
    return type;
}
