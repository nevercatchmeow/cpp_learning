#pragma once

#include <iostream>
#include <vector>

/*
================================================================================
==>vector：动态数组。
--------------------------------------------------------------------------------
	变长、存储紧凑、随机访问元素、查找快、增删慢。
注：不能使用vector存储bool，std::vector<bool>为假的容器，其实现采取了位域手段（紧凑表示）：
		1个二进制位存储1个bool，1个字节存储8个bool，故无法通过取地址获取指向bool对象的指针。
		（位不支持指针和引用）
================================================================================
*/

static void vectorTest()
{
	using Group = std::vector<float>;
	//typedef std::vector<float> Group;

	Group a;
	Group b = a;
	Group c(a);
	Group d(10);
	Group e(10, 1.0f);
	Group f(e.begin(), e.end());
	Group g({ 1.0f, 2.0f, 3.0f });
	Group h = { 1.0f, 2.0f, 3.0f };		// 列表初始化

	d.empty();							// 动态数组是否为空
	d.size();							// 动态数组当前大小
	d.max_size();						// 动态数组可达最大容量
	d.capacity();						// 动态数组当前容量
	d.reserve(100);						// 扩展容量（至100）（前提：当前容量小于100）
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

	// erase：删除后返回删除位置后的下一个元素，迭代器可能失效（重新分配内存）
	h.erase(h.begin());					// 删除指定（单个或区间）元素，返回删除位置后的下一元素
	h.erase(h.begin(), h.end());

	b.push_back(10.0f);					// 添加尾元素，迭代器可能失效（重新分配内存）
	b.pop_back();

	// insert：指定位置之后插入一个或多个元素，迭代器可能失效（重新分配内存）
	auto iter = b.insert(b.end(), 100.0f);		// 插入元素：b.end()后插入100.0f
	iter = b.insert(b.end(), 10, -10.0f);		// 插入元素：b.end()后插入10个-10.0f
	b.insert(b.end(), h.begin(), h.end());		// 插入元素：b.end()后插入h的所有元素
	// emplace：指定位置之前插入一个或多个元素。
	b.emplace(b.end(), 10.0f);					// 插入元素：b.end()前插入10.0f
	b.emplace_back(10.0f);						// 添加尾元素，与push_back的区别：push_back调用构造和拷贝构造；emplace_back直接在vector末尾构造，无拷贝、效率更高。
	b.resize(10);								// 改变元素个数，少则销毁，多则扩展。
	b.resize(100, 1.0f);
	b.clear();									// 清空元素：内存大小不变
	b.shrink_to_fit();							// 内存与存入的现有元素匹配（仅建议）

	// C接口互用
	std::vector<char> carr(100, 0);
	strcpy(&carr[0], "hakuno");
	//printf("%s\n", &carr[0]); 	//使用carr.data()代替。
	//printf("%s", carr.begin()); // 错误
	carr.data();
	std::cout << carr.data() << std::endl;
}