#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

/*
--------------------------------------------------
类模板中的成员函数类外实现：

--------------------------------------------------
*/

template<class T1, class T2>
class Hero
{
public:
	Hero(T1 name, T2 age);
	void showHero();

	T1 m_Name;
	T2 m_Age;
};

template<class T1, class T2>
Hero<T1, T2>::Hero(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
};

template<class T1, class T2>
void Hero<T1, T2>::showHero()
{
	cout << "Name:" << this->m_Name << ", Age:" << this->m_Age << endl;
};

void test()
{
	Hero<string, int> h("Teemo", 7);
	h.showHero();
}

int main()
{
	test();

	system("pause");
	return 0;
}