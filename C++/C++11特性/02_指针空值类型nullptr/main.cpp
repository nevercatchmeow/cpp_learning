/*
    指针空值类型nullptr：
        作用：代替NULL或0，可转换为需要的指针类型。

    NULL在C++和C中有不同含义：在C++中为0，在C中为(void *)0

    Compile: g++ main.cpp -o main -std=c++11
*/
#include <iostream>

void func(int p)
{
    std::cout << "void func(int p)" << std::endl;
}

void func(char *)
{
    std::cout << "void func(char* p)" << std::endl;
}

void test()
{
    int* ptr1 = NULL;
    char* ptr2 = NULL;
    double* ptr3 = NULL;
    void* ptr4 = NULL;

    // int* ptr5 = ptr4; // 无法隐式地将 void* 转换为 int* 
    int* ptr5 = (int*)ptr4; // 显示转换

    // int
    func(10);
    // char*
    func(nullptr);  // nullptr自动转换为需要的类型（此处转为char*）。
}

int main(int argc, char* argv[])
{
    test();

    return 0;
}