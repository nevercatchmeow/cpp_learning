#pragma once

#include <forward_list>

/*
================================================================================
==>forward_list：单向链表。
--------------------------------------------------------------------------------
不支持随机访问，访问首元素速度快，增删快，增删不会使迭代器失效。

forward_list追求性能，故无size()成员（会增加额外存储空间，影响插入删除效率）。
================================================================================
*/

static void forwardListTest()
{
	using Group = std::forward_list<float>;

	Group a;
	Group b = a;
	Group c(a);
	Group d(10);
	Group e(10, 1.0f);
	Group f(e.begin(), e.end());
	Group g({ 1.0f, 2.0f, 3.0f });
	Group h = { 1.0f, 2.0f, 3.0f };		// 列表初始化

	d.empty();							// 是否为空
	d.max_size();						// 可达最大容量
	
	// 赋值
	b = g;
	b.assign(3, 1.0f);					// 分派数据：3个1.0f
	b.assign(g.begin(), g.end());		// 分派数据：拷贝赋值g
	b.assign({ 1.0f, 2.0f, 3.0f });		// 分派数据：1.0f, 2.0f, 3.0f

	// 交换
	b.swap(a);							// 交换数据
	std::swap(a, b);					// 交换数据

	// 元素访问
	if (!b.empty())
	{
		b.front();						// 访问首元素
	}

	// 迭代器
	a.begin();							// 迭代器
	a.end();
	a.cbegin();							// 常量迭代器：不能修改指向的元素值
	a.cend();
	a.before_begin();	// 第一个元素的前一个位置，未定义，占位（仅用于自身算法）。
	a.cbefore_begin();	

	auto iterBegin = a.begin();

	b.erase_after(b.before_begin()); // return void
	b.erase_after(b.before_begin(), b.end()); // return void

	b.push_front(1.2f);
	b.emplace_front(1.3f);
	
	auto iter = b.insert_after(b.before_begin(), 100.0f);		// 插入元素：b.before_begin()后插入100.0f
	iter = b.insert_after(b.before_begin(), 10, -10.0f);		// 插入元素：b.before_begin()后插入10个-10.0f
	b.insert_after(b.before_begin(), h.begin(), h.end());		// 插入元素：b.before_begin()后插入h的所有元素

	b.resize(10);								// 改变元素个数，少则销毁，多则扩展。
	b.resize(100, 1.0f);
	b.clear();									// 清空元素

	// 算法
	b.remove(1.0f);
	b.remove_if([](auto v) { return v > 100.0f; });
	b.reverse(); // 反转
	b.sort(); // 排序
	g.sort();
	b.merge(g); // 合并排序（b, g均有序）
	c.unique(); // 去除相邻重复元素（配合排序使用）
	c.splice_after(c.before_begin(), b); // 拼接
}