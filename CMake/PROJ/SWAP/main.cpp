#include <iostream>

#include "./include/swap.h"

int main()
{
    int a = 3;
    int b = 5;

    auto swap = new Swap(a, b);
    std::cout << "Before swap:" << std::endl;
    swap->printInfo();
    swap->run();
    std::cout << "After swap:" << std::endl;
    swap->printInfo();

    return 0;
}