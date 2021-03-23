#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

/*
--------------------------------------------------
函数调用运算符重载：()

匿名函数对象：
	特点：当前行执行完立即释放
--------------------------------------------------
*/

class MyPrint
{
public:
	void operator()(string text)
	{
		cout << text << endl;
	}
};

void MyPrint2(string str)
{
	cout << str << endl;
}

void test_operTransfer1()
{
	MyPrint myPrint;
	myPrint("hello world"); //仿函数,本质是一个对象(函数对象)

	MyPrint2("hello world"); //普通函数
}

class MyAdd
{
public:
	int operator()(int a,int b)
	{
		return a + b;
	}
};

void test_operTransfer2()
{
	MyAdd myAdd;
	cout << myAdd(1, 1) << endl;
	cout << MyAdd()(1, 1) << endl; //匿名函数对象
}

int main(){

	//test_operTransfer1();
	test_operTransfer2();

	system("pause");
	return EXIT_SUCCESS;
}