#pragma once

#include <iostream>
#include <array>

/*
================================================================================
==>array：数组。
--------------------------------------------------------------------------------
分配在栈上、不会重新分配，支持随机访问。
	定长、存储紧凑、随机访问元素、查找快、增删慢。
================================================================================
*/

template<typename C>
void checkSize(C& c)
{
	if (c.size() > 3)
	{
		c[3] = 10;
	}
	c.at(3) = 10;
}

static void arrayTest()
{
	int abc[100];
	std::array<int, 100> a;
	std::array<int, 100> b = {};
	std::array<int, 100> c = { 1,2,3,4,5,6 };
	std::array<int, 100> d = { 1, 0 };

	//接口
	a.empty();		// 数组是否为空
	a.size();		// 数组当前大小
	a.max_size();	// 数组最大容量
					// 重载运算符：== < != > <= >=
	auto aa = a;

	aa.swap(a);		// 交换数组
	swap(aa, a);	// 交换数组

	//访问元素
	a[1];
	a.at(1);		// 获取数组索引位置处元素
	a.front();		// 获取数组首元素
	a.back();		// 获取数组尾元素
	checkSize(a);

	//迭代器
	a.begin();		// 迭代器
	a.end();
	a.cbegin();		// 常量迭代器：不能修改指向的元素值
	a.cend();
	a.rbegin();		// 反向迭代器
	a.rend();
	a.crbegin();	// 常量反向迭代器
	a.crend();

	// C接口互用
	std::array<char, 100> carr;
	strcpy(&carr[0], "hakuno");
	//printf("%s", &carr[0]);
	//printf("%s", carr.begin()); // 错误
	std::cout << carr.data() << std::endl;

	auto info = std::get<1>(carr);
	carr.fill(0);	// 填充元素
}