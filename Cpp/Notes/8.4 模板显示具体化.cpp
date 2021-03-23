#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

/*
--------------------------------------------------
函数模板缺陷：
	以三元运算符实现的返回最大值的函数模板为例，仅
	能比较基本数据类型的大小，无法比较结构体变量、
	对象及数组的大小，同时该模板虽能用于指针但比较
	的是地址大小而非指针指向的数据，故无意义。

模板的显示具体化：
	让模板针对某种具体的类型实现不同的算法。

--------------------------------------------------
*/

class Hero
{
public:
	Hero(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

//函数模板
template<class T>
bool Compare(T &a, T &b)
{
	if (a == b)
	{
		return true;
	}

	return false;
}

//函数模板的显示具体化
template<> bool Compare(Hero &a, Hero &b)
{
	if (a.m_Name == b.m_Name && a.m_Age == b.m_Age)
	{
		return true;
	}

	return false;
}

void test()
{
	Hero h1 = { "Teemo", 9 };
	Hero h2 = { "Teemo", 9 };
	if (Compare(h1, h2))
	{
		cout << "h1 == h1" << endl;
	}
	else
	{
		cout << "h1!=h2" << endl;
	}
}

int main()
{
	test();

	system("pause");
	return 0;
}