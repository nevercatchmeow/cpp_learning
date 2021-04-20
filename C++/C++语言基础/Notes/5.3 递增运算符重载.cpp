#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/*
--------------------------------------------------
++运算符重载：(局部函数实现)
	1. 前置++：
	2. 后置++：
--------------------------------------------------
*/

class myInter
{
	friend ostream& operator<<(ostream &cout, myInter& myInt);
public:
	myInter() :m_Num(0) {};
	myInter(int num) :m_Num(num) {};

	//前置++运算符重载
	myInter& operator++()
	{
		this->m_Num++;
		return *this;
	}

	//后置++运算符重载
	myInter operator++(int)
	{
		myInter tmp = *this;
		this->m_Num++;
		return tmp;
	}

private:
	int m_Num;
};

ostream& operator<<(ostream &cout, myInter& myInt)
{
	cout << "m_Name = " << myInt.m_Num << endl;
	return cout;
}

void test_operInc()
{
	myInter myInt;
	myInter myInt_tmp;

	myInt_tmp =	myInt++;
	cout << myInt_tmp << endl;
	cout << myInt << endl;

	++myInt;
	cout << myInt << endl;
}

int main()
{
	test_operInc();

	system("pause");
}
