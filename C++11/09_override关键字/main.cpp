/*
	override关键字：
		作用：
			1.确保派生类中声明的重写函数与基类的虚函数有相同的签名。
			2.明确表明重写基类的虚函数，保证重写虚函数的正确性，提高代码可读性。
	
	Compile: g++ main.cpp -o main -std=c++11
*/

#include <iostream>

class Base
{
public:
	virtual void test()
	{
		std::cout << "Base class..." << std::endl;
	}
};

class Child : public Base
{
public:
	void test() override
	{
		std::cout << "Child class..." << std::endl;
	}
};

void cpp_11()
{
	Child child;
	child.test();
}

int main()
{
	cpp_11();

	return 0;
}