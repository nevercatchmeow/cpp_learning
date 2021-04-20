#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

/*
--------------------------------------------------
成员函数作友元函数：

A类的成员函数作B类的友元函数：
1.B类中声明A类的长远函数：friend void A::func();
2.A类中成员变量(指向B类的指针)：B * m_b;
3.A类中绑定指针(通过构造函数)：
A();
{
this->m_b =  new B;
}
4.A类成员函数（友元函数）对B类成员访问：
this->m_building->m_SittingRoom //B类公有成员。
this->m_building->m_BedRoom //B类私有成员。

注：类成员函数的实现放在所有类的下面。
--------------------------------------------------
*/

class B;

class A
{
public:
	B * m_b;
	A();

	void func1();
	void func2();
};

class B
{
	friend void A::func1();
public:
	B();
	string b1;
private:
	string b2;
};

B::B()
{
	b1 = "B的公有b1";
	b2 = "B的私有b2";
}

A::A()
{
	this->m_b = new B;
}

void A::func1()
{
	cout << "（成员）友元函数正在访问" << this->m_b->b1 << endl;
	cout << "（成员）友元函数正在访问" << this->m_b->b2 << endl;
}

void A::func2()
{
	cout << "（成员）友元函数正在访问" << this->m_b->b1 << endl;
	//cout << "友元函数（成员）正在访问" << this->m_b->b2 << endl;
	//b2不可访问。
}

void test_friendMemberFunc()
{
	A a;
	a.func1();
	a.func2();
}

int main()
{
	test_friendMemberFunc();

	system("pause");
	return EXIT_SUCCESS;
}
