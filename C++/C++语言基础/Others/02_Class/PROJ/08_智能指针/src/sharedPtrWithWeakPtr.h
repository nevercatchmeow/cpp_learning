#pragma once

#include <iostream>
#include <memory>
#include <typeinfo>

/*
================================================================================
==>weak_ptr辅助shared_ptr解决对象相互依赖问题。
--------------------------------------------------------------------------------
================================================================================
*/

class B;

class A
{
public:
	//std::shared_ptr<B> b;
	std::weak_ptr<B> b;
	A() { std::cout << "class A 构造" << std::endl; }
	~A() { std::cout << "class A 析构" << std::endl; }
};

class B
{
public:
	//std::shared_ptr<A> a;
	std::weak_ptr<A> a;
	B() { std::cout << "class B 构造" << std::endl; }
	~B() { std::cout << "class B 析构" << std::endl; }
};

void sharedPtrWithWeakPtr()
{
	std::shared_ptr<A> sp1(new A);
	std::shared_ptr<B> sp2(new B);

	sp1->b = sp2;
	sp2->a = sp1;

	std::cout << "sp1引用计数：" << sp1.use_count() << std::endl; //引用计数-->1
	std::cout << "sp2引用计数：" << sp2.use_count() << std::endl; //引用计数-->1
}