#pragma once

#include <iostream>
#include <deque>
#include <vector>

/*
================================================================================
==>deque：双端队列。
--------------------------------------------------------------------------------
随机访问，首尾增删快，中间增删慢（大量元素复制与移动）。

两端都可增删。
元素访问及迭代慢于vector。
迭代器必须是smart_pointer,不能是寻常pointer（不同区块间跳转）。
不支持容量大小控制，除首尾两端外的增删元素都将使迭代器失效。
重新分配内存优于vector（无需复制元素）。
使用场景：
	1.数据增删发生在首尾。
	2.无需迭代器指向其元素。
	3.不再使用的元素必须释放。
================================================================================
*/

static void dequeTest()
{
	using Group = std::deque<float>;

	Group a;
	Group b = a;
	Group c(a);
	Group d(10);
	Group e(10, 1.0f);
	Group f(e.begin(), e.end());
	Group g({ 1.0f, 2.0f, 3.0f });
	Group h = { 1.0f, 2.0f, 3.0f };		// 列表初始化

	d.empty();							// 是否为空
	d.size();							// 当前大小
	d.max_size();						// 可达最大容量
	d.shrink_to_fit();					// 缩减容量

	// 赋值
	b = g;
	b.assign(3, 1.0f);					// 分派数据：3个1.0f
	b.assign(g.begin(), g.end());		// 分派数据：拷贝赋值g
	b.assign({ 1.0f, 2.0f, 3.0f });		// 分派数据：1.0f, 2.0f, 3.0f

	// 交换
	b.swap(a);							// 交换数据
	std::swap(a, b);					// 交换数据

	// 元素访问
	b[0];
	b.at(0);							// 访问指定索引元素
	if (!b.empty())
	{
		b.front();						// 访问首元素
		b.back();						// 访问尾元素
	}

	// 迭代器
	a.begin();							// 迭代器
	a.end();
	a.cbegin();							// 常量迭代器：不能修改指向的元素值
	a.cend();
	a.rbegin();							// 反向迭代器
	a.rend();
	a.crbegin();						// 常量反向迭代器
	a.crend();

	if (!a.empty())
	{
		a.pop_back();					// 删除尾元素
	}
	
	auto iterAfter = b.erase(b.begin());
	iterAfter = b.erase(b.begin(), b.end());

	b.push_back(10.0f);
	b.pop_back();
	b.push_front(1.2f);

	// insert：指定位置之后插入一个或多个元素，迭代器可能失效（重新分配内存）
	auto iter = b.insert(b.end(), 100.0f);		// 插入元素：b.end()后插入100.0f
	iter = b.insert(b.end(), 10, -10.0f);		// 插入元素：b.end()后插入10个-10.0f
	b.insert(b.end(), h.begin(), h.end());		// 插入元素：b.end()后插入h的所有元素
	
	b.emplace_front(1.3f);
	b.emplace(b.end(), 10.0f);					// 插入元素：b.end()前插入10.0f
	b.emplace_back(10.0f);						// 添加尾元素，与push_back的区别：push_back调用构造和拷贝构造；emplace_back直接在vector末尾构造，无拷贝、效率更高。

	b.resize(10);								// 改变元素个数，少则销毁，多则扩展。
	b.resize(100, 1.0f);
	b.clear();									// 清空元素：内存大小不变
	b.shrink_to_fit();							// 内存与存入的现有元素匹配（仅建议）

/*
	// 使用deque进行消息的接收与发送。

	using Buffer = std::vector<char>;
	using BufferGroup = std::deque<Buffer>;
	BufferGroup group;
	Buffer buffer;
	auto ok = readFromClient(socket, &buffer);
	if (ok)
	{
		group.emplace_back(std::move(buffer));
	}
	else
	{
		// handle error
	}

	while (!group.empty())
	{
		auto ok = sendToClient(socket, group.front());
		if (ok)
		{
			group.pop_front();
		}
		else
		{
			// handle error
			break;
		}
	}
*/
}