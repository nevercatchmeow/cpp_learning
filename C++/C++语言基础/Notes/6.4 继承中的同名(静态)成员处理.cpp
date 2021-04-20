#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
--------------------------------------------------
调用子类成员：

调用父类成员：
--------------------------------------------------
*/


class Base
{
public:
	Base()
	{
		this->m_A = 10;
	}

	void func() {}

	static void s_fun() {}
	static void s_fun(int s) {}
	static s_A;

	int m_A;
};

int Base::m_A  = 20;

class Son :public Base
{
public:
	Son()
	{
		this->m_A = 10;
	}

	void func() {}

	static void s_fun() {}
	static void s_fun(int s) {}
	static s_A;

	int m_A;
};

int Son::m_A  = 30;

void test_sameName()
{
	Son s1;
	s1.func();//调用子类成员
	s1.s_fun();
	Son::s_fun();
	cout << "s1.m_A = " << s1.m_A << endl;
	cout << "s1.s_A = " << s1.s_A << endl;
	cout << "Son::s_A = " << Son::s_A << endl;

	s1.Base::func();//调用父类成员
	s1.Base::s_fun();
	Son::Base::s_fun();
	cout << "s1.Base::m_A = " << s1.Base::m_A << endl;
	cout << "s1.Base::s_A = " << s1.Base::s_A << endl;
	cout << "Son::Base::s_A = " << Son::Base::s_A << endl;
}


int main() {
	test_sameName();

	system("pause");
	return EXIT_SUCCESS;
}
