/*
	final关键字：
		作用：
			1.修饰虚函数：限制该虚函数不能被子类及其后代重写（非基类中，否则与virtual相矛盾）。
			2.修饰类：限制该类不能被继承。
	
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
	// final修饰该子类的虚函数，该虚函数无法被该子类的后代重写。
	void test() final
	{
		std::cout << "Child class..." << std::endl;
	}
};

class GrandChild final : public Child
{
public:
	// 无法重写final函数"Child::test"
#if 0
	void test()
	{
		std::cout << "GrandChild class..." << std::endl;
	}
#endif // 0
};

// 不能将final类类型用作基类
#if 0
class GreatGrandChild : public GrandChild { };
#endif // 0

void cpp_11()
{
	GrandChild gc;
	gc.test();
}

int main()
{
	cpp_11();

	return 0;
}