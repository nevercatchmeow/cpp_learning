/*
	initializer_list模板类的使用：
		作用：在C++的STL容器中，进行任意长度的数据的初始化（初始化列表只能完成固定参数的初始化）。	
		使用：std::initializer_list

	Compile: g++ main.cpp -o main -std=c++11
*/

#include <iostream>
#include <initializer_list>
#include <vector>

void func(std::initializer_list<int> ls)
{
	auto it = ls.begin();
	for (; it != ls.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

class Test
{
public:
	Test(std::initializer_list<std::string> list)
	{
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			std::cout << *it << " ";
			m_names.push_back(*it);
		}
		std::cout << std::endl;
	}
private:
	std::vector<std::string> m_names;
};

void cpp_11()
{
	func({ 3,4,5,6,7,8 });	// 任意多个相同类型的对象放置在初始化列表构造出一个临时对象。

	Test t1({ "jack", "lucy", "kevin" });
	Test t2({ "have", "a", "nice", "day" });
}

int main()
{
	cpp_11();

	return 0;
}