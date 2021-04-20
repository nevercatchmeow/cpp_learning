#include <iostream>
#include <vector>
#include <algorithm>

/*
================================================================================
==> Lambda表达式
--------------------------------------------------------------------------------
 语法形式：[ capture ] ( params ) opt -> ret { body; };
	1.capture：	捕获列表，描述了lambda表达式可访问上下文中的变量。
		- []：		不捕获。
		- [=]：		按值捕获，一旦捕获将生成const副本，原值更改不会影响副本，且无法修改副本。
		- [&]：		按引用捕获。
		- [this]：	捕获当前对象。
	2.params：	参数，用于实现体中。
	3.opt：		选项，如mutable。
	4.ret：		返回值类型，可显式指出，也可自动推断（仅一条return时）。
	5.body：		实现体。

 示例：[](int x) {return x % 7 == 0; }
	1.无函数名，但可指定：auto f = [](int x ){ return x % 3 ==0; }; 后续使用可由f()代替。
	2.未声明返回值类型（根据返回值自动推断）
	3.默认情况下，Lambda函数为const函数，可使用mutable取消const属性。
================================================================================
*/

bool func7(int x)
{
	return x % 7 == 0;
}

void lambda()
{
	std::vector<int> vec(10);
	std::generate(vec.begin(), vec.end(), std::rand); // std::generate() 填充容器。

	//std::vector<int>::reverse_iterator iter;
	//for ( iter = vec.rbegin(); iter != vec.rend(); ++iter)
	std::vector<int>::iterator iter;
	for (iter = vec.begin(); iter != vec.end(); ++iter)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
	
	// std::count() 在序列中统计某个值出现的次数。
	//int count = std::count_if(vec.begin(), vec.end(), func7);  // std::count_if() 在序列中统计与谓词匹配的此处。
	int count = std::count_if(vec.begin(), vec.end(), [](int x) { return x % 7 == 0; });  // 使用 Lambda表达式 代替 func()函数。

	int a = 5;
	auto f = [=] () mutable { return a *= 5; };//按值捕获无法修改，需要先取消Lambda常量属性。
	std::cout << f() << std::endl;
} 

int main()
{
	lambda();

	return 0;
}