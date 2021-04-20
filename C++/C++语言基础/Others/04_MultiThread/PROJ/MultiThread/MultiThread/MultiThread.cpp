#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "CaculateByMultithread.h"
#include "ThreadInit.h"
#include "SharedVariable.h"
#include "TransferMoney.h"
#include "ThreadJoinOrDetach.h"
#include "ConditionVariable.h"

/*
================================================================================

https://blog.csdn.net/qq_38231713/category_10001159.html

创建线程：std::thread threadName(func);
线程休眠：std::this_thread::sleep_for(std::chrono::milliseconds(10));
获取当前线程ID：std::this_thread::get_id();
硬件支持并发数：std::thread::hardware_concurrency();
线程参数传递：std::thread threadName([=, &c] { add(a, b, c); });
			或 std::thread t4(add, a, b, std::ref(c));

原子操作变量类型：std::atomic_int m_count; （多线程访问结果仍错误）	
互斥锁（Mutex）：std::mutex m_mutex; lock()与unlock()成对出现。
自解锁（lock_guard）：定义局部变量时加锁（构造），出该对象作用域时解锁（析构）。

按顺序加锁：std::lock(a.Mutex, b.Mutex);// 在所有锁按特定顺序完全上锁后再继续向下。
等待解锁：std::lock_guard<std::mutex> lockA(a.Mutex, std::adopt_lock); // 已上锁，只待解锁（析构）。
		 std::lock_guard<std::mutex> lockB(b.Mutex, std::adopt_lock);
回收线程：threadName.join();
线程自动回收：threadName.detach();
线程放弃执行：std::this_thread::yield(); 相当于Sleep()，交出CPU时间片，允许其他线程执行（包括线程本身）。
			适用于频繁检查某个条件是否成立。
环境变量：std::condition_variable
配合std::condition_variable使用：std::unique_lock、
condition_variable.wait(lock, 条件)：释放lock锁，当条件达成后，重新获取锁。


获取时间：clock();
================================================================================
*/

void helloWorld()
{
	std::cout << "hello world" << std::endl;
}

void TestMultithread()
{
	std::thread t(helloWorld);
	std::cout << "hello main thread" << std::endl;
	t.join();
}

void GetSupportedThreads()
{
	 //硬件支持并发数
	unsigned int n = std::thread::hardware_concurrency(); // 12
	std::cout << n << " concurrent threads are supported.\n" << std::endl;
}

int main()
{
	//TestMultithread();
	//GetSupportedThreads();

	//CalByMultiThread();
	//ThreadInit();
	//SharedVariable();
	//TransferMoneyTest();
	//ThreadJoinOrDetach();
	ConditionVariable();


	return 0;
}