/*
	C++11对模板右尖括号的优化：
        C++11之前模板中的>>与流运算符>>冲突，前者需要使用空格隔开（如">空格>"）
	
	Compile: g++ main.cpp -o main -std=c++11
*/

#include <iostream>
#include <string>
#include <map>

template <typename T>
class Container
{
public:
	void print(T& t)
	{
		auto it = t.begin();
		for (; it != t.end(); it++)
		{
			std::cout << it->first << ", " << it->second << std::endl;
		}
	}
};

void cpp_11()
{
	std::map<int, std::string> m;
	m.insert(std::make_pair(1, "a"));
	m.insert(std::make_pair(2, "b"));
	m.insert(std::make_pair(3, "c"));
	m.insert(std::make_pair(4, "d"));
#if 0
	// Compile: g++ main.cpp -o main -std=c++03
	Container<std::map<int, std::string> > c; // C++03：>与>之间需要空格隔开
#else
    // Compile: g++ main.cpp -o main -std=c++11
	Container<std::map<int, std::string>> c; // C++11：>与>之间无需空格隔开
#endif // 0
	c.print(m);
}

int main()
{
	cpp_11();

	return 0;
}