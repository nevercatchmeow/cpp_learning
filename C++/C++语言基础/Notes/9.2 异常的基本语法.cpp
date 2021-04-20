#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

/*
--------------------------------------------------
栈解旋：
	从try代码块开始，到throw抛出异常之前，所有栈上
	的数据都会被释放掉，释放的顺序和创建顺序相反的。

C语言处理异常的缺陷：
	返回值不统一，返回值仅一个，无缺确认异常还是结果。

捕获到异常可不做处理，继续上抛到上一层。

--------------------------------------------------
*/

class MyException
{
public:
	void printError()
	{
		cout << "Warning：异常" << endl;
	}
};

class Hero
{
public:
	Hero(string name)
	{
		this->m_Name = name;
		cout << "验证栈解旋：构造函数调用(" << this->m_Name << ")" << endl;
	}
	~Hero()
	{
		cout << "验证栈解旋：析构函数调用(" << this->m_Name << ")" << endl;
	}
	string m_Name;
};

int myDivision(int a, int b)
{
	if (b == 0)
	{
		//return -1;
		//抛出int类型的异常
		//throw 1; 
		//抛出char类型的异常
		//throw 'a'; 
		//抛出double类型的异常
		//throw 3.14; 
		/*string str = "abc";
		throw str;*/

		//验证栈解旋
		Hero p1("Teemo");
		Hero p2("Yasuo");
		//抛出 MyException的匿名对象
		throw MyException();
	}
	return a / b;
}

void test()
{
	int a = 10;
	int b = 0;

	//C语言处理异常
	//	int iRet = myDivision(a, b);
	//	if(iRet == -1) 
	//	{
	//		return -1;
	//	}
	//	return iRet;

	try
	{
		myDivision(a, b);
	}
	catch (int)
	{
		cout << "int类型异常捕获" << endl;
	}
	catch (char)
	{
		cout << "char类型异常捕获" << endl;
	}
	catch (double)
	{
		//捕获到异常但不做处理，继续上抛到上一层
		//异常必须有函数进行处理，否则自动调用 terminate 函数，让程序中断
		throw;
		cout << "double类型异常捕获" << endl;
	}
	catch (MyException e)
	{
		e.printError();
	}
	catch (...)
	{
		cout << "其他类型异常捕获" << endl;
	}
}


int main() {

	test();

	system("pause");
	return EXIT_SUCCESS;
}
