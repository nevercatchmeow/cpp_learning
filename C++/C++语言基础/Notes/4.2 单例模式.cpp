#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/*
--------------------------------------------------
【单例模式】只有一个对象。
通过static实现。
【类在编译阶段分配内存】
在main函数执行前打印操作。（默认构造函数中...）
--------------------------------------------------
*/

class Printer
{
public:
	int Count;
	static Printer* getInstance()
	{
		return printer;
	}

	void draw(const char* str)
	{
		cout << "第" << Count << "次打印：";
		cout << str << endl;
		Count++;
	}
private:
	//构造函数私有化，不可以创建多个对象。
	Printer():Count(1) {};//默认构造。
	Printer(const Printer&) {};//拷贝构造

	static Printer* printer;//类内声明，类外初始化。
};

//编译阶段执行下列语句
Printer* Printer::printer = new Printer;//Printer作用域:相当于在Printer类内。

void test_Single()
{
	Printer * printer1 = Printer::getInstance();
	Printer * printer2 = Printer::getInstance();

	if (printer1 == printer2)
	{
		cout << "printer1 = printer2" << endl;
	}
	else
	{
		cout << "printer1 != printer2" << endl;
	}
	const char *p1 = "kitty";
	const char *p2 = "Teemo";
	printer1->draw(p1);
	printer2->draw(p2);
}


/*
--------------------------------------------------
在main函数执行前打印操作。（默认构造函数中...）
--------------------------------------------------
*/

class A {
public:
	A() {
		cout << "before the main function" << endl;
	}
	~A() {
		cout << "after the main function" << endl;
	};
};

A b;

int main() {
	cout << "now main function is working" << endl;

	test_Single();

	system("pause");
	return 0;
}
