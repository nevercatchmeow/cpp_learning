#pragma once

#include <iostream>
#include <memory>
#include <typeinfo>

#include "Object.h"

/*
================================================================================
==>unique_ptr
--------------------------------------------------------------------------------
特点：
	1.资源独占（编译期检查）
	2.不允许拷贝（拷贝构造及赋值）
	3.不支持数组
	4.不能用于容器
 使用：
	1.unique_ptr.reset();  绑定动态对象
	2.unique_ptr.release() 释放所有权
	3.std::move() 转移所有权（移动语义）
================================================================================
*/

void uniquePtrTest()
{
	typedef std::unique_ptr<Object> uniquePtrObj;
	typedef std::unique_ptr<Object[]> uniquePtrObjArray;

	uniquePtrObj unique_P1, unique_P2, unique_P3, unique_P4, unique_P5;	//创建空智能指针

	Object* p = new Object();
	uniquePtrObj unique_P0(p);

	// 1.绑定动态对象
	unique_P1.reset(new Object());		//绑定动态对象

	// 2.释放所有权
	Object* ptr = unique_P1.release();	//返回对象指针
	ptr->~Object();					//手动释放

	// 3.转移所有权
	unique_P4 = std::move(unique_P2);		//移动语义
	unique_P5.reset(unique_P3.release());

	// 4.支持数组
	Object* pn = new Object[2];
	uniquePtrObjArray unique_P6(pn);
}