/*
	统一的数据初始化方式-列表初始化：
		使用{}

	Compile: g++ main.cpp -o main -std=c++11
*/

#include <iostream>

class Person
{
public:
	Person(int num) : m_num(num) {}
	Person(int num, std::string name) : m_num(num), m_name(name) {}

private:
	int m_num;
	std::string m_name;
};

Person getPerson()
{
	return { 520, "KEVIN" };
}

void cpp_11()
{
	Person t1(520);
	Person t2 = 520; // 隐式类型转换，使用520作为参数构造对象，将对象指针赋给t2。
	Person t3 = { 520 };	// 初始化列表
	Person t4{ 520 };		// 初始化列表，可省略"="

	int* p = new int{ 520 };			// 初始化列表
	double b = double{ 52.1314 };		// 初始化列表
	int* array = new int[3]{ 1,2,3 };	// 初始化列表
}

int main()
{
	cpp_11();

	return 0;
}