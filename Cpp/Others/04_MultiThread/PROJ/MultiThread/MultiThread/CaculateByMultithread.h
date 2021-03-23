#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>

double caculate(double v)
{
	if (v <= 0)
	{
		return v;
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(10));

	return sqrt((v * v + std::sqrt((v - 5) * (v + 2.5)) / 2.0) / v);
}

template<typename Iter, typename Fun>
double visitRange(std::thread::id id, Iter iterBegin, Iter iterEnd, Fun func)
{
	auto curId = std::this_thread::get_id();
	if (id == std::this_thread::get_id())
	{
		std::cout << "main thread " << id << std::endl;
	}
	else
	{
		std::cout << "work thread " << curId << std::endl;
	}
	double v = 0;
	for (auto iter = iterBegin; iter != iterEnd; ++iter)
	{
		v += func(*iter);
	}
	return v;
}

void CalByMultiThread()
{
	auto mainThreadID = std::this_thread::get_id(); // 获取主函数线程ID

	std::vector<double> v;
	for (int i = 0; i < 1000; i++)
	{
		v.push_back(rand());
	}
	std::cout << v.size() << std::endl;

	/* 单线程计算 */
	double value = 0.0;

	auto nowc = clock();
	
	for (auto& info : v)
	{
		value += caculate(info);
	}

	auto finishc = clock();
	
	std::cout << "single thread: " << value << " used: " << finishc - nowc << std::endl;

	/* 多线程计算 */ 
	auto iter = v.begin() + (v.size() / 2);
	double anotherv = 0.0;

	nowc = clock(); // 计算耗时
	
	auto iterEnd = v.end();
	std::thread s([mainThreadID, &anotherv, iter, iterEnd]() { anotherv = visitRange(mainThreadID, iter, iterEnd, caculate); });
	auto halfv = visitRange(mainThreadID, v.begin(), iter, caculate);
	auto id = s.get_id(); // 获取线程ID
	s.join(); // 等待线程结束
	
	finishc = clock(); // 计算耗时

	std::cout << "multithread: " << (halfv + anotherv) << " used: " << finishc - nowc << std::endl;
}