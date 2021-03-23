#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/*
--------------------------------------------------
赋值运算符重载：()

编译器默认为类提供四个函数：
	1. 默认构造
	2. 析构
	3. 拷贝构造（值拷贝）
	4. operator=（值拷贝）

堆区默认赋值=为浅拷贝
--------------------------------------------------
*/

class Person
{
public:
	Person(const char* name, int age)
	{
		this->m_Name = new char[strlen(name) + 1];
		strcpy(this->m_Name, name);
		this->m_Age = age;
	}

	//=运算符重载
	Person& operator=(const Person& p)
	{
		//释放原堆区内容
		if (this->m_Name != NULL)
		{
			delete[] this->m_Name;
			this->m_Name = NULL;
		}

		this->m_Name = new char[strlen(p.m_Name) + 1];
		strcpy(this->m_Name, p.m_Name);
		this->m_Age = p.m_Age;
		return *this;
	}

	//拷贝构造重载（注）
	Person(const Person& p)
	{
		this->m_Name = new char[strlen(p.m_Name) + 1];
		strcpy(this->m_Name, p.m_Name);
		this->m_Age = p.m_Age;
	}

	~Person()
	{
		if (this->m_Name != NULL)
		{
			delete[] this->m_Name;
			this->m_Name = NULL;
		}
	}

	char* m_Name;
	int m_Age;
};


void test_operAssign()
{
	Person p1("Tom", 10);

	Person p2("Jerry", 19);
	p2 = p1;

	Person p3("", 0);
	p3 = p2 = p1;//连等操作实现，修改重载函数返回值


	Person p4 = p3;

	cout << "p1姓名： " << p1.m_Name << "  p1年龄： " << p1.m_Age << endl;
	cout << "p2姓名： " << p2.m_Name << "  p2年龄： " << p2.m_Age << endl;
	cout << "p3姓名： " << p3.m_Name << "  p3年龄： " << p3.m_Age << endl;

}


int main()
{
	test_operAssign();

	system("pause");
}
