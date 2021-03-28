/*
	C++11支持模板默认参数：
		注：类模板使用默认参数不可省略<>，函数模板可省略
	Compile: g++ main.cpp -o main -std=c++11
*/

#include <iostream>
#include <string>
#include <map>

/*
	类模板默认参数
*/
template <typename T=int, T t = 520>
class Test
{
public:
	void print()
	{
		std::cout << "current value: "  << t << std::endl;
	}
};

/*
	函数模板默认参数
*/
template <typename T = long, typename U = int>
void mytest(T t = 'A', U u = 'B') // 默认函数参数不能用于类型推导
{
	std::cout << "t: " << t << ", " << "u: " << u << std::endl;
}

void cpp_11()
{
	// 类模板使用默认参数不可省略<>，函数模板可省略
	Test<> test;
	test.print();

	// 无参数供推导，使用默认模板类型
	mytest();
	// 根据实参自动推导类型：void mytest<char, char>(char t, char u)
	mytest('a', 'b');	
	// 自动推导第二个参数类型：void mytest<int, char>(int t, char u)
	mytest<int>('a', 'b');
	// 自动推导第二个参数类型：void mytest<char, char>(char t, char u)
	mytest<char>('a', 'b');
	// 指定参数类型：void mytest<int, char>(int t, char u)
	mytest<int, char>('a', 'b');
	// 指定参数类型：void mytest<char, int>(char t, int u)
	mytest<char, int>('a', 'b');
}

int main()
{
	cpp_11();

	return 0;
}