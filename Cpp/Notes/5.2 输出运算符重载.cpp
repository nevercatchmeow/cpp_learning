#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/*
--------------------------------------------------
<<运算符重载：
1. 全局函数实现：
--------------------------------------------------
*/

class Person
{
	//友元函数：访问Person私有成员。
	friend ostream& operator<<(ostream &cout, Person& p);
public:
	Person(int a, int b) :m_A(a), m_B(b) {};

private:
	int m_A;
	int m_B;
};

//全局函数实现
ostream& operator<<(ostream &cout, Person& p)
{
	cout << "m_A = " << p.m_A << " , " << "m_B = " << p.m_B << endl;
	return cout;
}

void test_operOutput()
{
	Person p(10, 20);

	cout << p << endl;
}

int main()
{
	test_operOutput();

	system("pause");
	return 0;
}