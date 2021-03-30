/*
	通过using和typedef给模板定义别名：
		使用typedef定义模板别名：需要使用结构体包裹（定义泛型结构体）
		使用using定义模板别名：using mapType = std::map<int, T>;

	Compile: g++ main.cpp -o main -std=c++11
*/

#include <iostream>
#include <map>

// 遍历打印容器元素
template <typename T>
class Container
{
public:
	void print(T& t)
	{
		auto it = t.begin();
		for (; it != t.end(); ++it)
		{
			std::cout << it->first << ", " << it->second << std::endl;
		}
	}
};

#if 0
// template <typename T>
// typedef std::map<int, T> mapType; // 非法定义

// 使用typedef定义模板别名（需要使用struct包裹）。
template <typename T>
struct MyMap
{
	typedef std::map<int, T> mapType;
};
#else
// 使用using定义模板别名
template <typename T>
using mapType = std::map<int, T>;
#endif // 0

void cpp_11()
{
	std::map<int, int> m1;
	std::map<int, double> m2;
	std::map<int, std::string> m3;
#if 0
	// typedef定义模板别名测试
	MyMap<int>::mapType n1;
	MyMap<double>::mapType n2;
	MyMap<std::string>::mapType n3;

	n1.insert(std::make_pair(1, 1));
	n1.insert(std::make_pair(2, 2));
	n1.insert(std::make_pair(3, 3));
	Container<MyMap<int>::mapType> container1;
	container1.print(n1);

	n2.insert(std::make_pair(1, 1.10));
	n2.insert(std::make_pair(2, 2.20));
	n2.insert(std::make_pair(3, 3.30));
	Container<MyMap<double>::mapType> container2;
	container2.print(n2);

	n3.insert(std::make_pair(1, "A"));
	n3.insert(std::make_pair(2, "B"));
	n3.insert(std::make_pair(3, "C"));
	Container<MyMap<std::string>::mapType> container3;
	container3.print(n3);
#else
	// using定义模板别名测试
	mapType<int> n1;
	n1.insert(std::make_pair(1, 1));
	n1.insert(std::make_pair(2, 2));
	n1.insert(std::make_pair(3, 3));
	Container<mapType<int>> container1;
	container1.print(n1);

	mapType<double> n2;
	n2.insert(std::make_pair(1, 1.10));
	n2.insert(std::make_pair(2, 2.20));
	n2.insert(std::make_pair(3, 3.30));
	Container<mapType<double>> container2;
	container2.print(n2);

	mapType<std::string> n3;
	n3.insert(std::make_pair(1, "A"));
	n3.insert(std::make_pair(2, "B"));
	n3.insert(std::make_pair(3, "C"));
	Container<mapType<std::string>> container3;
	container3.print(n3);
#endif // 0
}

int main()
{
	cpp_11();

	return 0;
}