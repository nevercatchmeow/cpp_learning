#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

/*
--------------------------------------------------
类模板与友元函数：
	1.类模板内实现。
	2.类模板外实现（类后）。
	3.类模板后实现（类前）。

--------------------------------------------------
*/

//类模板声明
template<class T1,class T2>
class Hero;

//声明友元函数（必须先声明类模板Hero）
template<class T1,class T2>
void printHero2(Hero<T1, T2> &p);

//有元函数声明与实现（必须先声明类模板Hero）
template<class T1,class T2>
void printHero3(Hero<T1, T2>&p)
{
	cout << "类外实现（类前） --- Name： " << p.m_Name << " Age： " << p.m_Age << endl;
}

template<class T1, class T2>
class Hero
{
	//1.类模板内实现。
	friend void printHero(Hero<T1, T2> &p)
	{
		cout << "类内实现 --- Name： " << p.m_Name << " Age： " << p.m_Age << endl;
	}

	//2.类模板外实现（类后）。
	friend void printHero2<>(Hero<T1, T2> &p);

	//3.类模板后实现（类前）。
	friend void printHero3<>(Hero<T1, T2> &p);
public:
	Hero(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

private:
	T1 m_Name;
	T2 m_Age;
};

template<class T1,class T2>
void printHero2(Hero<T1, T2> &p)
{
	cout << "类外实现（类后） --- Name： " << p.m_Name << " Age： " << p.m_Age << endl;
}

void test()
{
	Hero <string, int> p("Teemo", 7);
	printHero(p);
	printHero2(p);
	printHero3(p);
}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}