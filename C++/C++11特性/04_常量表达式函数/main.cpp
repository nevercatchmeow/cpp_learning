/*
    常量表达式函数：
        作用：提高程序执行效率。
        1.修饰函数
            a.函数必须有返回值，且返回的表达式必须是常量表达式。
            b.函数在使用前，必须有相应的定义语句（在main中使用，应将函数定义在main函数上方）。
            c.在函数体中，不能出现非常量表达式之外的语句（using指令、typedef语句、static_assert断言、return语句除外）。
        2.修饰模板函数
            a.实际运行中判断返回值是否为常量表达式来决定是否忽略constexpr关键字。
        3.修饰构造函数
            a.构造函数的函数体必须为空，必须采用列表初始化方式为成员赋初值。

    Compile: g++ main.cpp -o main -std=c++11
*/
#include <iostream>

struct T
{
    constexpr T() : a(100) {}   // 必须使用列表初始化
    int a;
};

void test()
{
    constexpr T t;
    std::cout << t.a << std::endl;
}

int main(int argc, char* argv[])
{
    test();

    return 0;
}