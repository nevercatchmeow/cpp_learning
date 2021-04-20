#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

/*
--------------------------------------------------
静态类型转换：
	1.基本数据类型。
	2.父子类间指针或引用(向下转换不安全)。

动态类型转换：
	1.父子类间指针或引用。
	
常量转换：
	1.指针或引用
	
重新解释转换：
	1.最不安全一种转换，不建议使用

--------------------------------------------------
*/


//1、静态类型转换：static_cast
void test01()
{
	//允许内置数据类型之间转换
	char a = 'a';

	double d = static_cast<double>(a);

	cout << d << endl;

}

class Base{ virtual void func(){} };
class Son :public Base{ virtual void func(){} };
class Other{};

void test02()
{
	Base * base = NULL;
	Son * son = NULL;

	//语法：static_cast<目标类型>(原对象)
	//父子类间的指针或引用转换
	//向下类型转换（不安全）
	Son * son2 = static_cast<Son *> (base);
	//向上类型转换（安全）
	Base * base2 = static_cast<Base*>(son);
	//base 转为Other*
	//Other * other = static_cast<Other*>(base);  转换无效

}


//2、动态类型转换：dynamic_cast
void test03()
{
	//不允许内置数据类型之间转换
	//char c = 'c';
	//double d = dynamic_cast<double>(c);
}

void test04()
{
	Base * base = new Son;
	Son * son = NULL;

	//向下类型转换（多态安全）
	Son * son2 = dynamic_cast<Son*>(base);
	//向上类型转换（安全）
	Base * base2 = dynamic_cast<Base*>(son);
	//base 转 Other*
	//Other* other = dynamic_cast<Other*>(base); //无法转换
}

//3、常量转换：const_cast
void test05()
{
	//无法对非指针或非引用做const_cast转换
	const int * p = NULL;
	int * pp = const_cast<int*>(p);
	const int * ppp =  const_cast<const int *>(pp);
	//const int a = 10;
	//int b = const_cast<int>(a);
	int num = 10;
	int &numRef = num;
    const int& num2 = const_cast<const int&>(numRef);
}

//4、重新解释转换：reinterpret_cast（不安全）
void test06()
{
	int a = 10;
	int * p = reinterpret_cast<int*>(a);
	Base * base = NULL;
	//base 转 Other *
	Other * other = reinterpret_cast<Other *>(base);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}