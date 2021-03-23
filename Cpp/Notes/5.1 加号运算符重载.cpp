#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/*
--------------------------------------------------
+运算符重载：
	1. 成员函数实现：
	2. 全局函数实现：
--------------------------------------------------
*/

class Person
{
public:
	int m_A;
	int m_B;

	Person() {};

	Person(int a, int b) :m_A(a), m_B(b) {};

	//成员函数实现
	Person operator+(Person& p)
	{
		Person tmp;
		tmp.m_A = this->m_A + p.m_A;
		tmp.m_B = this->m_B + p.m_B;
		return tmp;
	}
};

//全局函数实现
Person operator+(Person& p1, Person& p2)
{
	Person tmp;
	tmp.m_A = p1.m_A + p2.m_A;
	tmp.m_B = p1.m_B + p2.m_B;
	return tmp;
}

//全局函数实现：可重载
Person operator+(Person& p1, int num)
{
	Person tmp;
	tmp.m_A = p1.m_A + num;
	tmp.m_B = p1.m_B + num;
	return tmp;
}

void test_operAdd()
{
	Person p1(10, 20);
	Person p2(20, 30);

	//Person p3 = p1 + p2;//局部函数实现与全局函数实现存在二义性。

	Person p4 = p1.operator+(p2);//成员函数实现的本质。
	Person p5 = operator+(p1, p2);//全局函数实现的本质。

	Person p6 = operator+(p1, 20);

	//cout << p3.m_A << " " << p3.m_B << endl;
	cout << p4.m_A << " " << p4.m_B << endl;
	cout << p5.m_A << " " << p5.m_B << endl;
	cout << p6.m_A << " " << p6.m_B << endl;
}

int main()
{
	test_operAdd();

	system("pause");
	return 0;
}