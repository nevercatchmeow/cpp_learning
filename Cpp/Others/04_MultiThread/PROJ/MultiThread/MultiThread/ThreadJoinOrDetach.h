#pragma once

#include <thread>

class Obj
{
public:
	Obj() { std::cout << "hello" << std::endl; }
	~Obj() { std::cout << "hakuno" << std::endl; }
};

class ThreadGuard
{
public:
	ThreadGuard(std::thread& t) : m_thread(t) {}
	~ThreadGuard() 
	{
		if (m_thread.joinable())
			m_thread.join();
	}

private:
	std::thread& m_thread;
};

void joinWorker() {}

void detachWorker()
{
	Obj obj;
	std::this_thread::sleep_for(std::chrono::seconds(1)); // 父进程结束，obj析构未执行。
}

void ThreadJoinOrDetach()
{
	Obj obj;

	std::thread j(joinWorker);
	ThreadGuard guard(j);

	std::thread d(detachWorker);
	d.detach(); // 线程运行完成后自动回收。（无法join()）

	//if (j.joinable()) 
	//	j.join(); // abort(errorcode); 使用abort终止程序。

	if (d.joinable())
		d.join(); 
}