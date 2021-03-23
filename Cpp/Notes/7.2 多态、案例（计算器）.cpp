#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
--------------------------------------------------
设计原则：开闭原则
	1.对扩展进行开放
	2.对修改进行关闭
	
纯虚函数：
	1.类中包含纯虚函数，则该类成为抽象类，无法实例化对象。
	2.抽象类的子类，必须重写父类中的纯虚函数，否则也属于抽象类。	
	3.函数实现部分替换为 " =0 "，如virtual int func() = 0;

计算器实现：
	1.抽象基类定义虚函数返回运算结果。
	2.抽象基类定义运算成员。
	3.派生类加法计算器、减法计算器、乘法计算器。

--------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

//常规实现：
//class calculator
//{
//public:
//
//	int getResult( string oper)
//	{
//		if (oper == "+")
//		{
//			return m_A + m_B;
//		}
//		else if (oper == "-")
//		{
//			return m_A - m_B;
//		}
//		else if (oper == "*")
//		{
//			return m_A * m_B;
//		}
//	}
//
//	int m_A;
//	int m_B;
//};


//利用多态实现计算器
class AbstractCalculator
{
public:
	virtual int getResult() = 0;

	int m_A;
	int m_B;
};

//加法计算器
class AddCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A + m_B;
	}
};

//减法计算器
class SubCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A - m_B;
	}
};

//乘法计算器
class MulCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A * m_B;
	}
};

//验证：不重写父类虚函数无法实例化对象。
class Test :public AbstractCalculator
{
	int getResult(){ return 0; };
};

void testCalculator()
{
	AbstractCalculator * calculator = new AddCalculator;
	calculator->m_A = 100;
	calculator->m_B = 200;
	cout << calculator->getResult() << endl;
	delete calculator;

	calculator = new SubCalculator;
	calculator->m_A = 100;
	calculator->m_B = 200;
	cout << calculator->getResult() << endl;
	delete calculator;

}

int main(){

	//抽象类无法实例化对象
	//AbstractCalculator abc;   
	
	//验证：子类不重写父类虚函数无法实例化对象。
	//Test t; 

	//测试计算器
	testCalculator();
	
	system("pause");
	return EXIT_SUCCESS;
}