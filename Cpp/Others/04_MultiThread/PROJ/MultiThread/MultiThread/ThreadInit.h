#pragma once

#include <iostream>
#include <thread>
#include <future>

void printString(const std::string& info1, const std::string& info2)
{
	std::cout << "3HAKUNO " << info1 << " " << info2 << std::endl;
}

void printAll(int a, int b, int c)
{
	std::cout << a << " " << b << " " << c << std::endl;
}

void add(int a, int b, int& c)
{
	c = a + b;
}

void ThreadInit()
{
	int a = 3;
	int b = 4;
	int c = 5;

	std::thread t1([=] { printAll(a, b, c); });
	t1.join();
	std::thread t2(printAll, a, b, c);
	t2.join();
	// 线程：绑定函数、传递参数。
	std::thread t3([=, &c] { add(a, b, c); }); // Lambda a、b传值 c传引用。
	t3.join();

	std::thread t4(add, a, b, std::ref(c)); // 非Lambda：取c的引用，std::ref() 常规引用
	t4.join();

	std::string abc("abc");
	std::string def("def");

	std::thread t5([&] { printString(abc, def); }); // Lambda方式
	t5.join();

	std::thread t6(printString, abc, def); // 非Lambda：传值（拷贝）
	t6.join();

	std::thread t7(printString, std::cref(abc), std::cref(def)); // 非Lambda：传递引用，std::cref() const引用
	t7.join();
}
