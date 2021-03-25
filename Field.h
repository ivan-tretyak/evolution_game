//
// Created by ivantretyak on 25.03.2021.
//

#ifndef GENES_FIELD_H
#define GENES_FIELD_H
#include "Section.h"
#include <string>
#include <iostream>

class Field {
private:
    std::vector<std::vector<Section>> field;
    unsigned int size;
public:
    Field(unsigned int s);
    void show();
    void move();
};


#endif //GENES_FIELD_H
