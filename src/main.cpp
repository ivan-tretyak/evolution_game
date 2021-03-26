#include <iostream>
#include <thread>
#include "../include/evolutiong_game/Field.h"
using namespace std::chrono_literals;

int main() {
    Field f(10);
    while (true) {
        f.show();
        std::this_thread::sleep_for(1s);
        f.move();
        system("clear");
    }
}
