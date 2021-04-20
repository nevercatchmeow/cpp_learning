#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
--------------------------------------------------
常函数：
	1.成员函数声明后面加const：void func() const{}
	2.修饰是this指针：const Type(className) * const this
	3.不能修改this指针指向的值
	4.用multable关键字修饰的成员变量在常函数中可以修改。

常对象：
	1.只能调用常函数。
	2.const Person p1;

this指针的本质： const className * const this
--------------------------------------------------
*/

class Person
{
public:
	Person(int age)
	{
		this->m_Age = age;
	}
	//常函数：修饰成员函数中的 this指针，让指针指向的值不可以修改。
	void showPerson() const
	{
		m_A = 100;
		//this指针的本质： const Person * const this 
		//this = NULL; 指针的指向不可以修改，而指针指向的值可以改
		cout << "person age = " << this->m_Age << endl;
	}

	void func()
	{
		m_Age = 100;
		cout << "func调用" << endl;
	}

	int m_Age;
	mutable int m_A;//特殊属性可修改
};

void test_Const_Func_O()
{
	const Person p1(10);//常对象。
	//p1.m_Age = 10;//不可修改。
	p1.m_A = 10;//mutable修饰，m_A可修改。
	p1.showPerson();
	//p1.func(); //ERROR：常对象只能调用常函数
}

int main() {
	test_Const_Func_O();

	system("pause");
	return EXIT_SUCCESS;
}