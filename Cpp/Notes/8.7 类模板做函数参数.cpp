#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

/*
--------------------------------------------------
类模板做函数参数：
	1.指定传入类型。
	2.参数模板化。
	3.类模板化。

--------------------------------------------------
*/

template<class T1, class T2>
class Hero
{
public:
	Hero(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	
	void showHero()
	{
		cout << "Name:" << this->m_Name << "  Age:" << this->m_Age << endl;
	}
	
	T1 m_Name;
	T2 m_Age;
};

//指定传入类型
void func1(Hero <string, int> &h)
{
	h.showHero();
}

void test1()
{
	Hero <string, int> p("Teemo", 7);
	func1(p);
	cout << endl;
}

//参数模板化
template<class T1, class T2>
void func2(Hero <T1, T2> &h)
{
	cout << "T1数据类型： " << typeid(T1).name() << endl;
	cout << "T2数据类型： " << typeid(T2).name() << endl;
	h.showHero();
}

void test2()
{
	Hero <string, int> p("ZOE", 777777);
	func2(p);
	cout << endl;
}

//类模板化
template<class T>
void func3(T &h)
{
	cout << "T数据类型： " << typeid(T).name() << endl;
	h.showHero();
}

void test3()
{
	Hero <string, int> p("YaSuo", 27);
	func3(p);
	cout << endl;
}

int main()
{
	test1();
	test2();
	test3();
		
	system("pause");
	return 0;
}