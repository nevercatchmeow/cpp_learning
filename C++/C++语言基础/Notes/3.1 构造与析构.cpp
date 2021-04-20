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

class Person
{

private:

public:
	int m_Age;

	Person()
	{
		cout << "Person的默认构造函数" << endl;
	}

	//按参数分为：有参构造、无参构造
	Person(int a)
	{
		m_Age = a;
		cout << "Person的有参构造函数" << endl;
	}
	//按类型分为：普通构造、拷贝构造
	Person(const Person &p)
	{
		m_Age = p.m_Age;
		cout << "Person的拷贝构造函数" << endl;
	}

/*
--------------------------------------------------
【构造函数的调用】
	1.括号法：
		Person p1(10);
		Person p1(p2);
		注：调用无参构造函数，不应使用括号，如 Person p(); 编译器会认为是声明。
	2.显示法：
		Person p3 = Person(10);
		Person p4 = Person(p3);
		Person(10);匿名对象，当前行执行完后，立即释放。
		注：不能使用拷贝构造创建匿名对象，如Person (p3)，编译器会认为是实例化对象Person p3，造成重定义错误。
	3.隐式法：
		使用explicit关键字修饰构造函数以禁止隐式类型转换方法来构造对象。
		Person p5 = 10;// Person p5 = Person(10); 不建议使用，可读性差！

【拷贝构造的调用时机】
	1.用已经创建好的对象初始化新建对象。
	2.值传递的方式给函数参数传值。
		void doWork1(Person p)
		{
			//p对p1进行拷贝（拷贝构造函数）
		}
		void test1()
		{
			Person p1(10);
			doWork(p1);
		}
	3.以值方式返回局部对象。（编译器对下列语句进行优化）
		Person doWork2() //值，非引用（被释放）
		{
		Person p;//默认构造
		return p;//拷贝构造（匿名对象）
		}
		void test2()
		{
		Person p = doWork2();//将匿名对象拷贝给p
		}

【构造函数的调用规则】
	1.编译器为类添加三个函数：默认构造（空实现）、拷贝构造（值拷贝）、析构（空实现）。
	2.如果自己提供了有参构造，编译器不再提供默认构造（需要自己创建），但仍然提供拷贝构造。
	3.自己提供拷贝构造，编译器不再提供其他构造。
--------------------------------------------------
*/

	~Person()
	{
		cout << "Person的析构函数" << endl;
	}

};

int main()
{
	Person a(10);
	Person b(a);
	cout << b.m_Age << endl;

	system("pause");

	return 0;
}