#pragma once

#include <iostream>
#include <memory>
#include <typeinfo>

#include "Object.h"

/*
================================================================================
==>auto_ptr
--------------------------------------------------------------------------------
特点：
	1.资源独占
	2.支持拷贝、赋值（拷贝语义，拷贝后原指针失效）
	3.不支持数组
	4.禁用于容器、参数传递（临时拷贝对象转移所有权）
	5.不能初始化指向非动态内存（非动态内存无法释放）
 弃用原因：避免因潜在的内存问题导致程序崩溃。
 使用：
	1.auto_ptr.reset();  绑定动态对象
	2.auto_ptr.release() 释放所有权
	3.std::move() 转移所有权（移动语义）
================================================================================
*/

void autoPtrTest()
{
	typedef std::auto_ptr<Object> autoPtrObj;
	typedef std::auto_ptr<int> autoPtrInt;

	// ① auto_ptr资源独占，以下运行时错误：同一资源无法释放两次。
	int* ptr1 = new int(3);
	autoPtrInt auto_P1(ptr1);
	//autoPtrInt auto_P2(ptr1);
	std::cout << "*ptr1 " << *ptr1 << std::endl;
	std::cout << "*auto_P1 " << *auto_P1 << std::endl;
	//std::cout << *auto_P2 << std::endl;

	// ② auto_ptr拷贝语义，以下运行时错误：ap3被拷贝后成为nullptr。
	int* ptr2 = new int(5);
	autoPtrInt auto_P3(ptr2);
	autoPtrInt auto_P4(auto_P3);
	//std::cout << "*auto_P3 " << *auto_P3 << std::endl;
	std::cout << "*auto_P4 " << *auto_P4 << std::endl;

	// ③ auto_ptr不支持数组（默认操作单个对象），以下运行时错误：数组中的n-1个对象无法析构。
	Object* pArray = new Object[2];
	//autoPtrObj ap5(pArray); // 不支持数组类型

	// auto_ptr.reset();  绑定动态对象
	autoPtrObj auto_P5, auto_P6;
	auto_P6.reset(new Object());
	// auto_ptr.release() 释放所有权
	auto_P6.release();
	// 通过std::move转移所有权
	auto_P6 = std::move(auto_P5); // auto_P6.reset(auto_P5.release())
}