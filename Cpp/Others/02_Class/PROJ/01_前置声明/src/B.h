//#pragma once

//#include "A.h"

class A;

class B {
private:
    A* a;
public:
    void method()
    {
        std::cout << " something happend... " << std::endl;
    }
};