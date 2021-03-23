#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
--------------------------------------------------
父类中构造、析构、拷贝构造 、operator=无法被子类继承。

子类中构造方法调用顺序：
	1. 父类构造。
	2. 其他成员构造。
	3. 自身构造。
析构顺序与构造【相反】。

利用初始化列表语法，显示调用父类中的其他构造函数：
	Son2(int a = 1000) :Base2(a)
	{
		//子类有参构造。
	}
--------------------------------------------------
*/

class Base1
{
public:
	Base1()
	{
		cout << "Base1的构造函数调用" << endl;
	}

	~Base1()
	{
		cout << "Base1的析构函数调用" << endl;
	}
};

class Other
{
public:
	Other()
	{
		cout << "Other的构造函数调用" << endl;
	}

	~Other()
	{
		cout << "Other的析构函数调用" << endl;
	}
};

class Son1 :public Base1
{
public:
	Son1()
	{
		cout << "Son1的构造函数调用" << endl;
	}

	~Son1()
	{
		cout << "Son1的析构函数调用" << endl;
	}

	Other other;
};

void test_classStructure1()
{
	Son1 s; 

}

class Base2
{
public:
	Base2(int a)
	{
		this->m_A = a;
		cout << "Base2的构造函数调用" << endl;
	}
	int m_A;
};

class Son2 :public Base2
{
public:
	//利用初始化列表语法，显示调用父类中的其他构造函数
	Son2(int a = 1000 ) :Base2(a)  
	{
		cout << "Son2的构造函数调用" << endl;
	}
};

void test_classStructure2()
{
	Son2 s;
	cout << s.m_A << endl;
}


int main(){
	//test_classStructure1();
	test_classStructure2();

	system("pause");
	return EXIT_SUCCESS;
}