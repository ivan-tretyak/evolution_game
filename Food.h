//
// Created by ivantretyak on 25.03.2021.
//

#ifndef GENES_FOOD_H
#define GENES_FOOD_H

#include "enums.h"
#include <utility>

class Food {
private:
    FoodType type;
    int energy;
public:
    Food(FoodType t, int e);
    int getEnergy();
    FoodType getType();
};


#endif //GENES_FOOD_H
