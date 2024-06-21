#include "A.h"
#include <iostream>

A* A::instance = nullptr;

A::A() {
    std::cout << "construct A" << std::endl;
}

A* A::getInstance() {
    std::cout << "get A" << std::endl;
    if (!instance) {
        instance = new A;
    }
    return instance;
}
