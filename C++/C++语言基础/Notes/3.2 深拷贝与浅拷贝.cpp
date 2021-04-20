#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

/*
--------------------------------------------------
位拷贝：拷贝地址。（浅拷贝）
值拷贝：拷贝内容。（深拷贝）
浅拷贝：拷贝内存。
深拷贝：拷贝对象。（先申请内存，然后把值拷贝过来。如下：）
	String::String(const String &other)
	{
		int length = strlen(other.m_data);
		m_data = new char[length+1];
		strcpy(m_data, other.m_data);
	}

如果不主动编写拷贝构造函数及赋值函数，编译器将以“位拷贝”的方式生成自动缺省的函数。
例如：类String的对象a、b，a.m_data = "hello"，b.m_data = "hello"
线将a赋值给b，执行位拷贝缺省函数：
	1.b.m_data原有内存未释放，造成内存泄漏。
	2.b.m_data和a.m_data指向同一块内存，任何一方改动都将影响另一方。
	3.对象被析构时，m_data被释放了两次。

例：
	string a("hello");
	string b("kitty");
	string c(a);//拷贝构造，切勿string c = a;
	c = b;//赋值
--------------------------------------------------
*/

class Person
{
public:
	char * m_Name;
	int m_Age;

	Person(char * name, int age)
	{
		m_Name = (char *)malloc(strlen(name) + 1); //堆区
		strcpy(m_Name, name);
		m_Age = age;
	}

	Person(const Person &p)
	{
		m_Name = (char *)malloc(strlen(p.m_Name) + 1); //堆区
		strcpy(m_Name, p.m_Name);
		m_Age = p.m_Age;
	}

	~Person()
	{
		if (m_Name != NULL)
		{
			free(m_Name);
			m_Name = NULL;
		}
	}
};

void test_Copy()
{
	Person p1("Teemo", 7);//有参构造
	cout << "姓名：" << p1.m_Name << "， 年龄：" << p1.m_Age << endl;

	Person p2(p1);
	cout << "姓名：" << p2.m_Name << "， 年龄：" << p2.m_Age << endl;
}

int main()
{
	test_Copy();

	system("pause");
	return 0;
}