#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/*
--------------------------------------------------
指针运算符重载：(局部函数实现)
	1. ->：
	2. *：

智能指针：
	new申请的内存在堆区，需要手动释放；将其作为智能指
	针的有参构造参数，通过栈内存自动释放（调用析构函数）。
--------------------------------------------------
*/

class Person
{
public:
	Person(int age)
	{
		this->m_Age = age;
		cout << "Person的有参构造函数。" << endl;

	}

	void showAge()
	{
		cout << "年龄是： " << this->m_Age << endl;
	}

	~Person()
	{
		cout << "Person的析构函数。" << endl;
	}

private:
	int m_Age;
};

class SmartPointer
{
public:
	SmartPointer(Person * person)
	{
		this->m_person = person;
	}

	//->运算符重载
	Person * operator->()
	{
		return this->m_person;
	}

	//*运算符重载
	Person& operator*()
	{
		return *m_person;
	}

	~SmartPointer()
	{
		if (this->m_person)
		{
			delete this->m_person;
			this->m_person = NULL;
		}
	}

private:
	Person* m_person;
};

void test_operPointer()
{
	// Person * p = new Person(18);
	// //(*p).showAge();
	// p->showAge();
	//delete p;//利用智能指针管理new出的Person的释放操作。
	SmartPointer sp(new Person(18));
	sp->showAge();//本质sp->->showAge();其中sp->是m_perspn;
	(*sp).showAge();

}

int main()
{
	test_operPointer();

	system("pause");
}
