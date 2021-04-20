#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/*
--------------------------------------------------
函数重载条件：
	1.在同一个作用域。
	2.函数名称相同。
	3.函数参数个数、类型、顺序不同。
注：
	const 引用可作为重载条件。
	函数返回值不能作为函数重载的条件。

	应 避免二义性。

重载实现原理：对函数名称进行修饰
--------------------------------------------------
*/

//引用可作为重载条件。
void func(int &a)
{
	cout << "void func(int &a)" << endl;
}

void func(const int &a)
{
/*
--------------------------------------------------
const int &a = 10;
//编译原理为：
int temp = 10;
int * const a = &temp;
--------------------------------------------------
*/
	cout << "void func(const int &a)" << endl;
}

void test_Overload()
{
	int a = 10;

	func(a);//调用func(int &a)
	func(10);//调用func(const int &a)
}

/*
--------------------------------------------------
不能定义 void func(int a){} ：避免二义性。
函数重载与默认参数。（存在二义性）
	void func(int a, int b = 10);//应取消参数默认值，void func(int a, int b);
	void func(int a);
--------------------------------------------------
*/


int main()
{
	test_Overload();

	system("pause");
	return 0;
}