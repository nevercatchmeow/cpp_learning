#pragma once

/*
================================================================================
==>enable_shared_from_this
--------------------------------------------------------------------------------
	1.类 T 继承 std::enable_shared_from_this<T> 。（为该类 T 提供成员函数： shared_from_this）
	2.T 类型对象 t 由名为 pt 的 std::shared_ptr<T> 类对象管理。
	3.调用 T::shared_from_this 成员函数，返回新的 std::shared_ptr<T> 对象，它与 pt 共享 t 的所有权。
 应用场景：当类A被share_ptr管理，且在类A的成员函数里需要把当前类对象作为参数传给其他函数时，需要传递一个指向自身的share_ptr。
 实现原理：
================================================================================
*/

#include <iostream>
#include <memory>

class Bad
{
public:
	std::shared_ptr<Bad> getptr() 
	{
		return std::shared_ptr<Bad>(this);
	}
	Bad() { std::cout << "Bad::Bad() called" << std::endl; }
	~Bad() { std::cout << "Bad::~Bad() called" << std::endl; }
};

class Good : public std::enable_shared_from_this<Good> // 注意：继承
{
public:
	std::shared_ptr<Good> getptr() 
	{
		return shared_from_this();
	}
	Good() { std::cout << "Good::Good() called" << std::endl; }
	~Good() { std::cout << "Good::~Good() called" << std::endl; }
};

//void esft_Bad()
//{
//	// 错误：每个shared_ptr都认为自己是对象仅有的所有者
//	std::shared_ptr<Bad> bp1(new Bad());
//	std::shared_ptr<Bad> bp2 = bp1->getptr();
//	// 打印bp1和bp2的引用计数
//	std::cout << "bp1.use_count() = " << bp1.use_count() << std::endl;
//	std::cout << "bp2.use_count() = " << bp2.use_count() << std::endl;
//}	// Bad 对象将会被删除两次

void esft_Good()
{
	std::shared_ptr<Good> gp1(new Good());
	std::shared_ptr<Good> gp2 = gp1->getptr();
	// 打印gp1和gp2的引用计数
	std::cout << "gp1.use_count() = " << gp1.use_count() << std::endl;
	std::cout << "gp2.use_count() = " << gp2.use_count() << std::endl;
}