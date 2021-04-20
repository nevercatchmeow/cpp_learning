/*
	使用初始化列表初始化非聚合类型：
		提供构造函数，初始化列表调用构造函数完成初始化。

	Compile: g++ main.cpp -o main -std=c++14
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

// 初始化列表调用构造函数返回匿名对象。
Person getPerson()
{
	return { 520, "Kevin" };	
}

void cpp_11()
{
	Person person{ 520, "Kevin" };	// 初始化列表调用构造函数完成对类的私有成员的初始化。
}

int main()
{
	cpp_11();

	return 0;
}