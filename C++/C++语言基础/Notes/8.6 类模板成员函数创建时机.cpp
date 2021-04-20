#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

/*
--------------------------------------------------
类模板中成员函数的创建时机：
	运行阶段确定T的类型后再创建成员函数。

--------------------------------------------------
*/

class Hero1
{
public:
	void showHero()
	{
		cout << "I'm Hero1." << endl;
	}

};

class Hero2
{
public:
	void showHero()
	{
		cout << "I'm Hero2." << endl;
	}

};

template<class T>
class Hero
{
public:
	void func()
	{
		obj.showHero();
	}

	T obj;
};

void test()
{
	Hero <Hero1> h1;
	h1.func();

}

int main()
{
	test();

	system("pause");
	return 0;
}