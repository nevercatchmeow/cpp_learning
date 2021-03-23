#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/*
--------------------------------------------------
构造：对象初始化。
	1.无返回值，函数名与类相同
	2.可以有参数，可以重载
	3.由编译器自动调用，仅一次

析构：对象清理。
	1.无返回值，函数名与类相同，在类名前加~
	2.无参数，不能重载
	3.由编译器自动调用，仅一次
--------------------------------------------------
*/

//函数默认参数
int func_DefaultPara1(int a = 10, int b = 10)
{
	return a + b;
}

//如果有一个参数有了默认值，从此参数开始以后的参数必须有默认值。
int func_DefaultPara2(int a = 10, int b = 10, int c = 10)
{
	return a + b + c;
}

//函数的声明与实现，只能有一个提供默认参数。
int func_DefaultPara3(int a = 10, int b = 10);
int func_DefaultPara3(int a, int b)
{
	return a + b;
}


//占位参数：只写一个类型进行占位，调用时必须要传入调用值。（可以有默认值）
int PlaceholderPara1(int a, int)
{
	return a;
}

int PlaceholderPara2(int a, int = 1)
{
	return a;
}

//占位参数用途：???（布吉岛）

int main()
{
	int r1, r2, r3, r4, r5;

	r1 = func_DefaultPara1();//20
	r2 = func_DefaultPara2(20);//40
	r3 = func_DefaultPara3(20);//30

	r4 = PlaceholderPara1(10, 1);//10
	r5 = PlaceholderPara2(50);//50

	cout << r1 << endl;
	cout << r2 << endl;
	cout << r3 << endl;
	cout << r4 << endl;
	cout << r5 << endl;

	system("pause");
	return 0;
}