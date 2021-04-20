#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

/*
--------------------------------------------------
类模板与继承：
	必须指定父类中的T数据类型，才能给子类分配内存。

--------------------------------------------------
*/

//父类
template<class T>
class Base
{
public:
	T m_A;
};

//子类
template<class T1, class T2>
class Son : public Base<T2>
{
public:
	Son()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
	T1 m_B;
};

void test()
{
	Son<int, double> s;
}

int main()
{
	test();

	system("pause");
	return 0;
}