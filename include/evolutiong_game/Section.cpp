//
// Created by ivantretyak on 25.03.2021.
//

#include "Section.h"

Section::Section() {
    Section::type = empty;
}

void Section::changeSection(Cell c) {
    switch (c.getType()) {
        case omniglot:
            Section::type = cell_hebivor;
            break;
        case predator:
            Section::type = cell_predator;
            break;
    }
    Section::item = c;
}

void Section::changeSection(Food f) {
    switch (f.getType()) {
        case meat:
            Section::type = food_meat;
            break;
        case grass:
            Section::type = food_grass;
            break;
    }
    Section::item = f;
}

SectionType Section::getType() {
    return type;
}

std::variant<Cell, Food>& Section::getItem() {
    return item;
}

void Section::erase() {
    Section::type = empty;
}

void Section::setBorder() {
    Section::type = border;
}
