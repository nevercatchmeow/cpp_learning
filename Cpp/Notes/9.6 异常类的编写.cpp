#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

/*
--------------------------------------------------
异常类编写：
	
--------------------------------------------------
*/

class MyOutOfRangeException:public exception
{
public:

	MyOutOfRangeException( const char * str)
	{
		//const char * 可以隐式类型转换为 string
		this->m_errorInfo = str;
	}

	MyOutOfRangeException(string str)
	{
		this->m_errorInfo = str;
	}

	virtual const char *  what() const
	{
		//将string 转为 const char * 
		return m_errorInfo.c_str();
	}

	string m_errorInfo;
};

class Person
{
public:
	Person(int age)
	{
		if (age < 0 || age > 150)
		{
			throw MyOutOfRangeException( string( "年龄必须在0到150之间"));
		}
		else
		{
			this->m_Age = age;
		}
	}

	int m_Age;
};

void test()
{
	try
	{
		Person p(1000);
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
	}
}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}