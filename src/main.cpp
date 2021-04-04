#include <iostream>
#include <thread>
#include "../include/evolutiong_game/Field.h"
using namespace std::chrono_literals;

int main() {
    Field f(50);
    while (true) {
        f.show();
        f.info();
        std::this_thread::sleep_for(1s);
        f.move();
        system("clear");
    }
}
