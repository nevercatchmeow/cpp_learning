#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

#include "Array.h"
#include "Vector.h"
#include "Deque.h"
#include "List.h"
#include "ForwardList.h"
#include "Set.h"
#include "Map.h"


/*
================================================================================
==>STL：集成抽象容器、迭代器、算法。
--------------------------------------------------------------------------------
容器：
	序列式容器：array、vector、deque、list、forward_list （数组、指针、链表）
	关联式容器：set、map、multiset、multimap、hash_set、hash_map（二叉树、红黑树、lgn）
	无顺序容器：unordered_set、unordered_map、unordered_multiset、unordered_multimap


stack（栈）
queue（队列）
priority_queue (优先级顺序 队列)
string（字符串）
bitset（代替bool、sizeof(bool) == 1, 占8位，但表达是否只需要1位）

regex（正则表达式）
rand（随机数）
thread、async、future（多线程语言层实现）
time（时间相关）

基本知识
	1.容器内元素应满足的条件：
		a.可拷贝或搬移（move）且无副作用
		b.可赋值。
		c.可销毁。
	2.序列式容器元素，应用默认的构造函数。
	3.对于某些操作（std::find），元素需要定义 ==
	4.对于关联式容器，排序准则默认 < > std::less
	5.无顺序容器，需提供hash函数。
	6.stl容器内存放元素值而非引用。

STL设计原则：效率优先、安全为此（不采用异常）。

================================================================================
*/

// 容器通用接口
template <typename T>
void containerAllInterface(T& a, T& b)
{
	T c;
	T d(a);						// copy
	T e = a;					// copy
	T f(std::move(a));			// a == NULL
	auto iterB = b.begin();
	auto iterE = b.end();
	T g(iterB, iterE);
	b.size();					// std::forward_list不提供（追求空间上的极致效率）
	auto isEmpty = b.empty();	// return b.size() == 0;（算法不一）
	b.max_size();				// 最大容量
	if (b == c) {}				// 元素必须定义 ==
	if (b != d) {}				//  !(b == d)
	if (b < e) {}				// unordered_set、unordered_map 不支持
								// == != < <= > >=

	e = b;
	e = std::move(b);
	e.swap(g);					// std::array 线性的
	swap(e, g);					// std::array 除外

	e.cbegin();					// -> const_iterator
	auto ea = e.cbegin();
	auto eea = e.cbegin();
	*eea;
	*ea;

	e.cend();
	e.clear();					// std::forward_list、std::array不支持
}

void stlTest()
{
	std::vector<int> a;
	std::vector<int> b;

	containerAllInterface(a, b);
}

int main()
{
	//stlTest();

	//arrayTest();
	//vectorTest();
	//dequeTest();
	//listTest();
	//forwardListTest();
	//setTest();
	mapTest();

	return 0;
}