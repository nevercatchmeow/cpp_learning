/*
	使用初始化列表初始化聚合类型：
		聚合类型：
			1.普通数组。
			2.无自定义构造函数、无私有或保护的非静态数据成员、无基类、无虚函数的类（class、struct、union）。

	Compile: g++ main.cpp -o main -std=c++14
*/

#include <iostream>

#if 0
struct T1
{
	int x;
	long y;
protected:
	int z;
}t1{ 1, 100, 2 };	// Error: 对于含有保护的非静态成员的类，无法使用初始化列表进行初始化。

struct T2
{
	int x;
	long y;
protected:
	static int z;
}t2{ 1, 100, 2 };	// Error: 类中有静态成员可以使用初始化列表，但不能初始化其静态成员。
#else
struct T2
{
	int x;
	long y;
protected:
	static int z;
}t2{ 1, 100 };	// 类中有静态成员可以使用初始化列表，但不能初始化其静态成员。
int T2::z = 2;	// 类中静态成员在类外初始化。

struct T3
{
	int a = 5;
	int array[3]{ 1,2,3 };
	int c;
};
#endif // 0

void cpp_11()
{
	T3 t{ 11, {2,3,4}, 12 };
	std::cout << "a: " << t.a << std::endl;
	std::cout << "array[0]: " << t.array[0] << std::endl;
	std::cout << "array[1]: " << t.array[1] << std::endl;
	std::cout << "array[2]: " << t.array[2] << std::endl;
	std::cout << "c: " << t.c << std::endl;
}

int main()
{
	cpp_11();

	return 0;
}