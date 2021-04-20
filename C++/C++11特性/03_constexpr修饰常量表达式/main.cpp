/*
    constexpr修饰常量表达式：
        作用：定义常量表达式以提高程序执行效率。

    const双重语义：只读变量、修饰常量。

    常量表达式与非常量表达式的区别：
        常量表达式在程序编译阶段计算结果。
        非常量表达式在程序运行阶段计算结果。

    constexpr与const：
        1.在定义常量时，两者等价，即都在编译阶段计算结果。
        2.对于内置数据类型，可使用constexpr定义；自定义类型则不适用。
        3.使用建议：修饰常量时使用constexpr，修饰只读时使用const。

    Compile: g++ main.cpp -o main -std=c++11
*/
#include <iostream>

// 无法在定义struct或class时使用constexpr修饰。
struct T
{
    int a;
};

void func(const int num)
{
    // 可使用constexpr修饰自定义类型。
    constexpr T t{100};
    // t.a = 20; // 常量，不可修改。

    int a1 = 520;
    int a2 = 250;
    const int count = 24;

    // int array1[a1]; // VC中非法：表达式必须具有常量值，a1不可作为常量。
    int array2[count];
    // int array3[num]; // VC中非法：表达式必须具有常量值，num不可作为常量。
}

void test()
{
    func(10);
}

int main(int argc, char* argv[])
{
    test();

    return 0;
}