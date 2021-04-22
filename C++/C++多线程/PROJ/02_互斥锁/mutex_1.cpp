/*
    文件：mutex_1.cpp
    功能：通过互斥体lock与unlock保护共享全局变量

    编译：g++ -Wall -g -std=c++11 -pthread mutex_1.cpp -o mutex_1
*/

#include <iostream> 
#include <thread>
#include <mutex>
#include <chrono>

std::chrono::milliseconds interval(100);

std::mutex mutex;
// 多线程共享的全局变量，多线程操作，使用mutex保护
int job_shared = 0; 
// 单线程独占的全局变量，无需mutex保护
int job_exclusive = 0;

void job_1()
{
    mutex.lock();
    // 持锁等待
    std::this_thread::sleep_for(5 * interval);  
    ++job_shared;
    std::cout << "job_1 shared (" << job_shared << ")\n";
    mutex.unlock();
}

void job_2()
{
    while (true) 
    {    
        // 无限循环，尝试获得锁
        if (mutex.try_lock()) 
        {     
            // 尝试获得锁成功则修改'job_shared'
            ++job_shared;
            std::cout << "job_2 shared (" << job_shared << ")\n";
            mutex.unlock();
            return;
        }
        else 
        {      
            // 尝试获得锁失败则修改'job_exclusive'
            ++job_exclusive;
            std::cout << "job_2 exclusive (" << job_exclusive << ")\n";
            std::this_thread::sleep_for(interval);
        }
    }
}

int main()
{
    std::thread thread_1(job_1);
    std::thread thread_2(job_2);

    thread_1.join();
    thread_2.join();

#ifdef WIN32
    system("pause");
#endif

    return 0;
}