/*
	基于范围的for循环：
		语法：for(遍历声明 : 要遍历的对象) { } ， 遍历对象：表达式、容器、数组、初始化列表。

		范围for与普通for的区别（对于容器）：
			范围for：返回容器的元素。
			普通for：返回迭代器。

		范围for的特点：只访问一次被遍历对象。

		注：set元素、map的key只读，无法修改。

	Compile: g++ main.cpp -o main -std=c++11
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>

// 全局vector
std::vector<int> vec{ 1,2,3,4,5,6 };

// 用于检测范围for对被遍历对象的访问次数。
std::vector<int>& getRange()
{
	std::cout << "get vector range..." << std::endl;
	return vec;
}

void cpp_11()
{
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9 };
	//for (auto& it : v)	// 使用引用类型：提高效率（避免拷贝）、可修改元素值
	for (const auto& it : v)	// 使用const限制元素为只读。
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;

	std::map<int, std::string> m{ {1, "lucy"}, {2, "kevin"}, {3, "jack"} };
	// 基于范围的for循环：auto推导获得容器中的value_type，即map的一个对组（std::pair）对象。
	for (auto& it : m)
	{
		std::cout << "id: " << it.first << " , name: " << it.second << std::endl;
	}

	// 普通的for循环：auto推导获得迭代器类型。
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		std::cout << "id: " << it->first << " , name: " << it->second << std::endl;
	}

	std::set<int> s{ 1,2,3,4,5 };
	for (auto& item : s)
	{
		//std::cout << item++ << std::endl;	// Error: set只读。
		std::cout << item << std::endl;
	}

	// 检测结果：范围for只访问一次被遍历的对象。
	for (auto val : getRange())
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

int main()
{
	cpp_11();

	return 0;
}