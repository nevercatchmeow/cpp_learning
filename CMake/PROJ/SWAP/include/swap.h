#ifndef _SWAP_H_
#define _SWAP_H_

#include <iostream>

class Swap
{
private:
    int _a;
    int _b;
public:
    Swap(int &a, int &b) : _a(a), _b(b) {}
    ~Swap() {}
    void run();
    void printInfo();
};

#endif