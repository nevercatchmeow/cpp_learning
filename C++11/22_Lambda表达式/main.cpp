/*
	Lambda表达式：
		优势：
			1.声明式的编程风格：就地定义匿名函数对象
			2.简洁：避免代码膨胀。
			3.灵活：实现功能闭包。
		捕获列表：
			[]：不捕获任何变量
			[&]：按引用捕获变量
			[=]：按值捕获变量
			[=, &foo]：foo按引用捕获，其余按值捕获
			[bar]：只按值捕获bar变量，不捕获其他变量
			[&bar]：只按引用捕获bar变量，不捕获其他变量
			[this]：捕获当前类中的this指针
		参数列表：使用()，无参可省略（不建议）。
		函数体：同普通函数。
		返回值类型：-> returnType
		调用：()

		Lambda的本质：
			仿函数，默认使用const修饰。

		注：使用mutable去除值拷贝形式捕获的变量的只读属性

	Compile: g++ main.cpp -o main -std=c++11
*/

#include <iostream>
#include <functional>

void func(int x, int y)
{
	int a = 7;
	int b = 9;;

#if 0
	[=, &x]() mutable {
		int c = a;
		int d = x;
		b++;	// Error：通过值捕获的变量具有只读属性，无法修改。
		std::cout << "b: " << b;
	};			// 此处只为Lambda函数定义，调用使用()。
#else
	// 定义形参z接受数据。
	// 返回值类型：int
	auto f = [=, &x](int z) mutable -> int	// 若返回初始化列表时，auto无法推导，须指明返回值类型。
	{	
		int c = a;
		int d = x;
		b++;	// 使用mutable去除通过值拷贝方式捕获的变量b的只读属性，但是外部的b不会变化。
		std::cout << "b: " << b << std::endl;
		return b + z;
	}(88);		// 定义并调用Lambda函数：传入实参。
#endif // 0

	std::cout << "b: " << b << std::endl;
	std::cout << "f: " << f << std::endl;

	using ptr = void(*)(int);
	
	ptr p = [](int x)
	{
		std::cout << "x: " << x << std::endl;
	};
	p(11);

	std::function<void(int)> f1 = [=](int x)
	{
		std::cout << "x: " << x << std::endl;
	};
	f1(11);
	
	// 使用绑定器
	std::function<void(int)> f2 = bind([=](int x)
	{
		std::cout << "x: " << x << std::endl;
	}, std::placeholders::_1);
	f2(11);
}

void cpp_11()
{
	func(1, 2);
}

int main()
{
	cpp_11();

	return 0;
}