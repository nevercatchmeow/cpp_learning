#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/*
--------------------------------------------------
this指针:

1.指针存在于类的成员函数中，【指向被调用函数类实例的地址】。
2.一个对象的this指针并不是对象本身的一部分，不会影响sizeof（）的结果。
3.this指针的作用域是在类内部。
4.成员函数（非静态）的第一个默认参数是 *const  this。（隐含形参）
5.this指针在成员函数的开始前构造，在成员函数结束后清除，生命周期和其他函数参数一样。
6.this指针存放的位置取决于编译器，栈、寄存器或全局变量（静态存储区）。

this类型：className *

this指针的使用
(1)在类的非静态成员函数中返回类对象本身的时候，直接使用 return *this;
(2)当参数与函数成员变量名相同时，应使用 this->age = age;

this指针的作用：
1.解决名称冲突。
2.对对象的各成员进行访问。
--------------------------------------------------
*/

/*
--------------------------------------------------
A.b与A->b两者的区别：
1、A.B则A为对象或者结构体；
2、A->B则A为指针，->是成员提取，A->B是提取A中的成员B，A只能是指向类、结构、联合的指针；
--------------------------------------------------
*/


class Person
{
public:
	Person(int age)
	{
		//用途：解决名称冲突。
		//age = age;//如何区分形参与类成员。
		this->age = age;
	}

	bool Compare(Person& p)
	{
		if (this->age == p.age)
		{
			return true;
		}
		return false;
	}

	Person& personAddPerson(Person&)
	{
		this->age += age;
		return *this;//*this是本体。（解引用）
	}

	int age;
};

void test_this()
{
	Person p1(10);
	Person p2(20);

	bool ret = p1.Compare(p2);
	if (ret)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}
}



int main()
{
	test_this();

	system("pause");
	return 0;
}