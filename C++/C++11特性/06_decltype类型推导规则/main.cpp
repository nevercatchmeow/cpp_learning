/*
    decltype类型推导：
        说明：

    Compile: g++ main.cpp -o main -std=c++11
*/
#include <iostream>

class Test
{
public:
    std::string text;
    static const int value = 110;
};

void test()
{
    int x = 90;
    const int& y = x;
    decltype(x) a = x;  // a : int
    decltype(y) b = x;  // b : const int&
    decltype(Test::value) c = 0;            // c : const int
    decltype(Test::text) d = "hello Kevin"; // d : std::string
    Test t;
}

int main(int argc, char* argv[])
{
    test();

    return 0;
}