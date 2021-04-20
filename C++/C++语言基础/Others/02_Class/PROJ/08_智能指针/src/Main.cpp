#include <iostream>
#include <memory>
#include <typeinfo>

#include "auto_ptr.h"
#include "unique_ptr.h"
#include "shared_ptr.h"
#include "weak_ptr.h"
#include "sharedPtrWithWeakPtr.h"
#include "enable_shared_from_this.h"

/*
================================================================================
==>智能指针
--------------------------------------------------------------------------------
	 智能指针
	 auto_ptr
	 shared_ptr 共享资源（引用计数）
	 unique_ptr 独占资源
	 weak_ptr   辅助shared_ptr

前提：禁止手动管理资源。
	1.一个裸指针不应使用两个智能指针同时管理。
	2.使用weak_ptr配合shared_ptr可打破循环引用。
	3.类的内部接口中，如需将this作为参数传入，该类应派生自enable_shared_from_this。
	4.shared_ptr、weak_ptr与裸指针相比，空间更大（两个计数+一个指针，至少24字节），效率低。
================================================================================
*/

int main()
{
	//autoPtrTest();
	//uniquePtrTest();
	//sharedPtrTest();
	//weakPtrTest();
	//sharedPtrWithWeakPtr();

	//esft_Bad();
	esft_Good();

	system("pause");
}