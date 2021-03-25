#include <iostream>
#include <thread>
#include "../include/evolutiong_game/Field.h"
using namespace std::chrono_literals;

int main() {
    Field f(10);
    f.show();
    std::cout<< "\n==========\n";
    f.move();
    std::cout<< "\n==========\n";
}
