#pragma once

#include <iostream>
#include <memory>
#include <typeinfo>

#include "Object.h"

/*
================================================================================
==>shared_ptr
--------------------------------------------------------------------------------
特点：
	1.资源共享（引用计数）
	2.拷贝构造、赋值
	3.交换语义
缺陷：无法解决析构函数相互依赖。
================================================================================
*/

typedef std::shared_ptr<Object> sharedPtrObj;

// 值传递：临时变量拷贝，引用计数+1
void print(sharedPtrObj shared_P)
{
	std::cout << "值传递，引用计数：" << shared_P.use_count() << std::endl; // 0
}

// 引用传递：引用计数不变。
void printRef(const sharedPtrObj& shared_P)
{
	std::cout << "引用传递，引用计数：" << shared_P.use_count() << std::endl; // 0
}

void sharedPtrTest()
{
	sharedPtrObj shared_P1;
	// ① shared_ptr.use_count() 当前指向资源的引用总和
	std::cout << "引用计数：" << shared_P1.use_count() << std::endl; // 0

	Object* objPtr = new Object();
	sharedPtrObj shared_P2(objPtr);		// 绑定动态对象，引用计数+1，当前为1。
	sharedPtrObj shared_P3(shared_P2);	// 拷贝构造，引用计数+1，当前为2。
	sharedPtrObj shared_P4 = shared_P2;	// 拷贝赋值，引用计数+1，当前为3。
	shared_P3.reset();					// 解除引用，引用计数-1，当前为2。等价于obj2 = nullptr;

	sharedPtrObj shared_P5;				// 裸指针（无参）
	shared_P4.swap(shared_P5);			// 指针交换，引用计数不变。
	std::swap(shared_P4, shared_P5);	// 交换语义，引用计数不变。
	shared_P4 = nullptr;				// 解除引用，引用计数-1，当前为1。

	// ② 返回指向shared_P2管理资源的原始的Object*指针。
	auto pObject = shared_P2.get();			// 返回原始的Object*指针。
	std::cout << "Type of shared_ptr.get() is :" << typeid(pObject).name() << std::endl;
	if (pObject) // pObject非空指针
	{
		std::cout << pObject->getValue() << std::endl;
	}

	if (shared_P2)
	{
		std::cout << "m_Value id is " << shared_P2->getValue() << std::endl;	// 指针访问：1
		std::cout << "m_Value id is " << (*shared_P2).getValue() << std::endl;	// 对象访问：1
	}

	// ③ 检查shared_P1是否是所管理资源的唯一所有者。
	std::cout << "引用计数：" << shared_P2.use_count() << std::endl;	// 引用计数为1。
	std::cout << "唯一所有：" << shared_P2.unique() << std::endl;		// shared_P2是当前资源的唯一所有者：1

	// ④ 避免值传递（防止引用计数变化）
	print(shared_P2); // 值传递，临时变量拷贝，引用计数+1，禁用！
	printRef(shared_P2);
}