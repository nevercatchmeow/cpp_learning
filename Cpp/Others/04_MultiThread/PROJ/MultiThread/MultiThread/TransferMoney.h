/*
* 转账：
*/

#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <cstdlib>

struct BankAccount
{
	BankAccount(int b) : Balance(b) {}
	int Balance;
	std::mutex Mutex;
};

void transferMoney(BankAccount& a, BankAccount& b, int money)
{
	if (&a == &b)
		return;	// 解决单线程下：a==b造成的死锁。

	std::lock(a.Mutex, b.Mutex /*...*/);// 在所有锁按特定顺序完全上锁后再继续向下。
	std::lock_guard<std::mutex> lockA(a.Mutex, std::adopt_lock); // 已上锁，只待解锁（析构）。
	std::lock_guard<std::mutex> lockB(b.Mutex, std::adopt_lock);
	if (a.Balance < money) return;
	a.Balance -= money;
	b.Balance += money;

	//if (&(a.Mutex) < &(b.Mutex))// 解决多线程下造成的死锁。
	//{
	//	std::lock_guard<std::mutex> lockA(a.Mutex);
	//	std::lock_guard<std::mutex> lockB(b.Mutex);
	//	if (a.Balance < money) return;
	//	a.Balance -= money;
	//	b.Balance += money;
	//}
	//else
	//{
	//	std::lock_guard<std::mutex> lockA(b.Mutex);
	//	std::lock_guard<std::mutex> lockB(a.Mutex);
	//	if (a.Balance < money) return;
	//	a.Balance -= money;
	//	b.Balance += money;
	//}
	std::cout << a.Balance << " " << b.Balance << std::endl;
}

void TransferMoneyTest()
{
	BankAccount teemo(500);
	BankAccount yasuo(500);

	// 单线程下：若a==b，将造成死锁。
	transferMoney(teemo, teemo, 75);

	// 多线程下：thread 1 和 thread 2 同时阻塞，将造成死锁。
	//transferMoney(teemo, yasuo, 15);
	std::thread thread1([&] { transferMoney(teemo, yasuo, 15); });
	//transferMoney(yasuo, teemo, 15);
	std::thread thread2([&] { transferMoney(yasuo, teemo, 15); });

	thread1.join();
	thread2.join();
}