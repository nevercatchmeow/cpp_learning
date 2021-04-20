#include <iostream>

class A
{
public:
	A() {}
	//~A() {}
};

class B : public A
{
public:
	B() {}

	// 默认生成的析构函数为内联函数，会在调用处展开。
	// 析构函数执行时，先调用成员析构函数，再调用派生类析构函数，由于使用内联函数导致程序异常扩张。
	// 因此需要自己定义类时声明析构，并在实现文件中实现。
	~B () noexcept(false)
	{
		std::cout << "bye class B" << std::endl;
		throw std::string("error B"); // 错误，try catch 只能捕获一个异常（同时存在两个异常，core dumped）
	}

private:
	std::string m_value;
};

class GoodB : public B
{
public:
	// 自定义析构函数 与 编译器默认生成析构函数 都声明为 noexcept。
	//~EvilB() { throw std::string("error"); } // 等效于 ~EvilB() noexcept { throw std::string("error"); }
	~GoodB() noexcept(false) 
	{ 
		throw std::string("error"); 
		delete m_value; // 如果异常在 delete 前， m_value将永远丢失。
	} // 通过 noexcept(false) 使析构函数抛出异常。
	// 此处异常非立即捕获，而是执行其他析构后再捕获。
private:
	int* m_value;
};

void test()
{
	try
	{
		GoodB b;
		GoodB c; // 错误，try catch 只能捕获一个异常 ==> 不建议在析构函数中抛出异常。
	}
	catch (std::string const& e)  
	{
		std::cout << "catch you evil" << e << std::endl;
	}
}

int main()
{
	test(); // abort() 程序崩溃。

	return 0;
}

/*
================================================================================
==>析构函数不应抛出异常
--------------------------------------------------------------------------------
原因：
	1.析构函数中的异常并非即时捕获，且 try catch 不能同时处理两个异常。
	2.如果异常抛出在delete前，将使资源丢失。
================================================================================
*/