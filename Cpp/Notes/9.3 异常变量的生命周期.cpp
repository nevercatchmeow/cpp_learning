#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

/*
--------------------------------------------------
异常变量的生命周期：
	throw MyException();  catch (MyException e) 
	调用拷贝构造函数，效率低
	
	throw MyException();  catch (MyException &e)  
	只调用默认构造函数，效率高（推荐）
	
	throw &MyException(); catch (MyException *e) 
	对象会提前释放掉，不能在非法操作
	
	throw new MyException();   catch (MyException *e) 
	只调用默认构造函数 自己要管理释放
--------------------------------------------------
*/

class MyException
{
public:
	MyException()
	{
		cout << "MyException默认构造函数调用" << endl;
	}

	MyException(const MyException & e)
	{
		cout << "MyException拷贝构造函数调用" << endl;
	}

	~MyException()
	{
		cout << "MyException析构函数调用" << endl;
	}
};

void doWork()
{
	throw  new MyException();
}

void test()
{
	try
	{
		doWork();
	}

	catch (MyException *e)
	{
		cout << "自定义异常捕获" << endl;
		delete e;
	}
}

int main(){

	test();
	system("pause");
	return EXIT_SUCCESS;
}