/*
	委托构造函数：
		在某个构造函数中调用其它构造函数：构造函数链式调用。
		建议位置：初始化列表。
        优点：代码复用，优化代码结构。

	Compile: g++ main.cpp -o main -std=c++11
*/

#include <iostream>

class Test
{
public:
	Test() {};
	Test(int max)
	{
		this->m_max = max > 0 ? max : 100;
	}
	Test(int max, int min) : Test(max)	// 委托构造函数（建议位置：初始化列表）
	{
		//this->m_max = max > 0 ? max : 100; // 冗余代码
		this->m_min = min > 0 && min < max ? min : 1;
	}
	Test(int max, int min, int mid) : Test(max, min)	// 委托构造函数（建议位置：初始化列表）
	{
		//this->m_max = max > 0 ? max : 100;	// 冗余代码
		//this->m_min = min > 0 && min < max ? min : 1;	// 冗余代码
		this->m_mid = mid < max&& mid > min ? mid : 50;
	}

	void print()
	{
		std::cout << "MAX: " << m_max << std::endl;
		std::cout << "MID: " << m_mid << std::endl;
		std::cout << "MIN: " << m_min << std::endl;
	}
private:
	int m_max;
	int m_min;
	int m_mid;
};

void cpp_11()
{
	Test test(10, 6, 5);
	test.print();
}

int main()
{
	cpp_11();

	return 0;
}