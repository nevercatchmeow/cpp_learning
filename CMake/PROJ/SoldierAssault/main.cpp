// g++ .\main.cpp .\src\Gun.cpp .\src\Solider.cpp -Iinclude -o main -Wall -g -O2

#include "Gun.hpp"
#include "Solider.hpp"

void test()
{
    Solider xusanduo("XSD");
    xusanduo.addGun(new Gun("AK47"));
    xusanduo.addBulletToGun(20);
    xusanduo.fire();
}

int main()
{
    test();
    return 0;
}