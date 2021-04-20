#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/*
--------------------------------------------------
使用explicit关键字修饰构造函数以禁止隐式类型转换方法来构造对象。
--------------------------------------------------
*/

class Person
{
public:
	explicit Person() {};
	explicit Person(int age) :m_Age(age) {};

	int m_Age;
};

void test_explicit()
{
	Person p0;
	Person p1(10);
	//Person p2 = 10;//此项被禁止。（ERROR：不存在从int转换到Person的适当构造函数）
}



int main()
{
	test_explicit();

	system("pause");
	return 0;
}
