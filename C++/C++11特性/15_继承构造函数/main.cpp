/*
	继承构造函数：
		子类调用父类构造函数：using Base::Base;
		子类调用父类的同名方法：using Base::func;

	Compile: g++ main.cpp -o main -std=c++11
*/

#include <iostream>

class Base
{
public:
	Base(int i) : m_i(i) {}
	Base(int i, double d) : m_i(i), m_d(d) {}
	Base(int i, double d, std::string s) : m_i(i), m_d(d), m_s(s) {}

	void func(int i)
	{
		std::cout << "base class: i = " << m_i << std::endl;
	}

	void func(int i, std::string s)
	{
		std::cout << "base class: i = " << m_i << " , s = " << m_s << std::endl;
	}
	
public:
	int m_i;
	double m_d;
	std::string m_s;
};

class Child : public Base
{
public:
#if 0
	Child(int i) : Base(i) {}
	Child(int i, double d) : Base(i, d) {}
	Child(int i, double d, std::string s) : Base(i, d, s) {}
#else
	// 继承构造
	using Base::Base;
	// 使用父类中被隐藏的方法
	using Base::func;

	void func()
	{
		std::cout << "child class : i'm MRZ" << std::endl;
	}
#endif // 0
};

void cpp_11()
{
	Child child(520, 13.14, "Rain");
	std::cout << "int: " << child.m_i << std::endl;
	std::cout << "double: " << child.m_d << std::endl;
	std::cout << "std::string: " << child.m_s << std::endl;

	child.func();

	child.func(24);			// 默认调用失败：基类的func方法被隐藏。
	child.func(24, "MRZ");	// 默认调用失败：基类的func方法被隐藏。
}

int main()
{
	cpp_11();

	return 0;
}