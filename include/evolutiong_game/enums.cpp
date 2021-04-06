//
// Created by ivantretyak on 05.04.2021.
//

#include "enums.h"

std::string getNumeration(Direction t) {
    switch (t) {
        case up:
            return "Вверх";
        case down:
            return "Вниз";
        case right:
            return "Вправо";
        case left:
            return "Влево";
    }
    return "";
}

std::string getNumeration(CellType t){
    switch (t) {
        case omniglot:
            return "Травоядное";
        case predator:
            return "Хищник";
    }
    return "";
}