/*
	返回值类型后置：
		实现：auto + decltype。
		作用：用于解决模板函数的返回值类型未知时无法声明模板参数（返回值）类型的问题。
	
	Compile: g++ main.cpp -o main -std=c++11
*/

#include <iostream>

#if 0
template <typename R, typename T, typename U>
R add(T t, U u)
{
	return t + u;
}
#else
// 返回值类型后置：auto + decltype 实现。
template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u)
{
	return t + u;
}
#endif // 0

void cpp_11()
{
	int x = 520;
	double y = 13.14;

#if 0
	// 原始方法：使用时需要知道模板函数内部实现方式（缺点）。
	auto ret = add<decltype(x + y), int, double>(x, y);
	std::cout << "ret: " << ret << std::endl;
#else
	// 返回值类型后置：
	// auto ret = add<int, double>(x, y);
	auto ret = add(x, y);	// 使用auto，可省略模板函数参数类型声明。
	std::cout << "ret: " << ret << std::endl;
#endif // 0
}

int main()
{
	cpp_11();

	return 0;
}