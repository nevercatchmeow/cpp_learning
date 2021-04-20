#pragma once

#include <iostream>
#include <memory>
#include <typeinfo>

#include "Object.h"

/*
================================================================================
==>weak_ptr
--------------------------------------------------------------------------------
 weak_ptr 弱指针  辅助shared_ptr，判断对象是否存在，避免访问不存在的对象。
	1.使用对象时，需要先转换为shared_ptr。
	2.绑定到shared_ptr，但不会使shared_ptr计数+1。
	3.weak_ptr.lock()：返回智能指针。
	4.weak_ptr.expired()：智能指针是否为nullptr。
================================================================================
*/

typedef std::shared_ptr<Object> sharedPtrObj;
typedef std::weak_ptr<Object> weakPtrObj;

void weakPtrTest()
{
	sharedPtrObj shared_P(new Object());
	weakPtrObj weak_P1;
	weakPtrObj weak_P2(shared_P);
	weakPtrObj weak_P3(shared_P);
	std::cout << "当前 new Object() 引用计数：" << shared_P.use_count() << std::endl; // 1
	{
		std::cout << "new Object() 是否唯一引用：" << shared_P.unique() << std::endl; // 1

		// ① 返回share_ptr管理的智能指针。
		auto shared_Ptr = weak_P2.lock(); // class std::shared_ptr<class Object>
		if (shared_Ptr == nullptr)
		{
			std::cout << "weak_P2绑定的共享指针：nullptr。" << std::endl;
		}
		else
		{
			std::cout << "当前 new Object() 引用计数：" << shared_Ptr.use_count() << std::endl; // 2（shared_P + shared_Ptr）
			shared_P.reset();
		}

		// ② 绑定的shared_ptr是否为nullptr（对象是否已被销毁）。
		auto isNotExist = weak_P2.expired();
		if (isNotExist)
		{
			std::cout << "weak_P2绑定的共享指针为0（对象已被销毁）" << std::endl;
		}
		else
		{
			std::cout << "weak_P2绑定的共享指针非0（对象仍然存活）" << std::endl;
		}
	}
}