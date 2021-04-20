#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
--------------------------------------------------
1.多继承：
2.菱形继承：
	Alpaca从Sheep和Camel继承到两个m_Age：
		虚继承从虚基类继承得到vbptr指针(虚基类指针)。
		虚基类指针指向一个虚基类表(vbtable)。
		虚基类表记录了偏移量，通过偏移量可找到唯一m_Age。
--------------------------------------------------
*/

//虚基类
class Animal
{
public:
	int m_Age;
};

//虚继承
class Sheep : virtual public Animal {};

//虚继承
class Camel :virtual public Animal {};

//多继承
class Alpaca :public Sheep, public Camel
{
public:

};


void test_ExtendDiamond()
{
	Alpaca ap;

	ap.Sheep::m_Age = 10;
	ap.Camel::m_Age = 20;

	cout << "Sheep::m_Age = " << ap.Sheep::m_Age << endl;
	cout << "Camel::m_Age = " << ap.Camel::m_Age << endl;
	cout << "age = " << ap.m_Age << endl;

	//当发生虚继承后，Sheep和Camel类中继承了一个vbptr指针。
	//vbptr指针(虚基类指针)：指向的是一个虚基类表(vbtable)。
	//虚基类表中记录了偏移量，通过偏移量可以找到唯一的m_Age。
}


int main()
{
	test_ExtendDiamond();

	system("pause");
	return EXIT_SUCCESS;
}