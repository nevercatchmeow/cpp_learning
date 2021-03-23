#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/*
--------------------------------------------------
初始化列表的优点：
	提高效率。（如构造函数中赋值操作导致二次拷贝构造。）

以下情况必须在构造函数时写成初始化列表形式：
	1.类成员中存在常量，如 const int a;   因为常量只能初始化不能赋值。
	2.类成员中存在引用，同样的只能初始化不能赋值。
	3.类成员的基类或成员类没有定义默认构造函数

（注意，只要显示定义了类的构造函数，则编译器不再提供默认构造函数。如果没有定义构造函数，则编译器会提供默认构造函数）
--------------------------------------------------
*/

class Person
{
public:
	int m_A;
	int m_B;
	int m_C;

	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}

};

void test_InitList()
{
	Person p(10, 20, 30);
}

int main()
{
	test_InitList();

	system("pause");
	return 0;
}