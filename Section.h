//
// Created by ivantretyak on 25.03.2021.
//

#ifndef GENES_SECTION_H
#define GENES_SECTION_H

#include "Cell.h"
#include "Food.h"
#include <variant>

class Section {
private:
    SectionType type;
    std::variant<Cell, Food> item;
public:
    Section();
    void changeSection(Cell c);
    void changeSection(Food f);
    SectionType getType();
    std::variant<Cell, Food> getItem();
    void erase();
};


#endif //GENES_SECTION_H
