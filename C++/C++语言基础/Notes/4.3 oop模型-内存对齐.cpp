#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/*
--------------------------------------------------
只有非静态成员变量，处于类对象。

查看内存对其：
#pragma pack(show)
--------------------------------------------------
*/

class Person1 {};

void test_MemoryAlignment1()
{
	Person1 p1;
	cout << sizeof(p1) << endl;
	//分配1个字节，（区分）空对象在内存上独一无二的地址。
}


class Person2
{
	int m_Age;
};

void test_MemoryAlignment2()
{
	Person2 p2;
	cout << sizeof(p2) << endl;//分配4个字节。
}


class Person3
{
	int m_Age;
	void func() {}
	static int m_B;
};

void test_MemoryAlignment3()
{
	Person3 p3;
	cout << sizeof(p3) << endl;//分配4个字节。 仅有非静态成员变量（其余成员不在类中）。
}


int main()
{
	test_MemoryAlignment1();
	test_MemoryAlignment2();
	test_MemoryAlignment3();

	system("pause");
	return 0;
}