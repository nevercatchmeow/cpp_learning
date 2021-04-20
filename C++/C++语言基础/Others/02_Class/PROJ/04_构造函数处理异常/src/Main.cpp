#pragma once
#include <iostream>
#include <string>

using namespace std;

class A {
public:
	A() { cout << "构造 A 对象!" << endl; }
	~A() { cout << "销毁 A 对象!" << endl; }
};

class B {
public:
	B() {
		throw exception("测试：在B的构造函数中抛出一个异常"); // 抛出异常，程序控制权转移到class Tester的构造函数处。
		cout << "构造 B 对象!" << endl;
	};
	~B() { cout << "销毁 B 对象!" << endl; };
};

class Tester {
public:
	Tester(const string& name, const string& address) : m_Name(name), m_Address(address)
	{
		try
		{
			a = new A();
			b = new B();
		}
		catch (const std::exception&)
		{

			delete a;
			delete b;
			throw;   // 继续传递异常
		}
		cout << "构造 Tester 对象!" << endl;
	}
	~Tester()
	{
		delete a;
		delete b;
		cout << "销毁 Tester 对象!" << endl;
	}
private:
	string m_Name;
	string m_Address;
	A* a = NULL;
	B* b = NULL;
};

int main()
{
	Tester* tes = NULL;
	try
	{
		tes = new Tester("Hakuno", "486"); 
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	};
	delete tes; // 删除NULL指针是安全的

	system("pause");
	return 0;
}

/*
================================================================================
==>构造失败应抛出异常
--------------------------------------------------------------------------------
	swap中不抛出异常。

	1. 在构造函数中抛出异常是C++中通知对象构造失败的唯一方法。
	2. 构造函数中抛出异常，对象的析构函数将不会被执行，创建的对象不会被删除，导致内存泄漏。
	3. 当对象发生部分构造时，已经构造完毕的子对象（非动态分配的）将会逆序地被析构。
================================================================================
*/