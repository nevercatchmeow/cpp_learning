/*
	通过using定义类型别名和函数指针别名：
		1.using定义类型别名：using uint_t = unsigned int;
		2.using定义函数指针：
			using func_ptr = int(*)(int, std::string);
			func_ptr f = mytest;

	Compile: g++ main.cpp -o main -std=c++11
*/

#include <iostream>

int mytest(int a, std::string str)
{
	std::cout << str << std::endl;
	return a;
}

#if 0
// typedef 旧的类型名 新的类型名
typedef unsigned int uint_t;
// typedef 定义函数指针
typedef int(*func_ptr)(int, std::string);
#else
// using 新的类型 = 旧的类型
using uint_t = unsigned int;
// using 定义函数指针
using func_ptr = int(*)(int, std::string);
#endif // 0

void cpp_11()
{
	uint_t a = 10;
	uint_t b = 15;

	func_ptr f = mytest;
	mytest(a, "hello_");
}

int main()
{
	cpp_11();

	return 0;
}