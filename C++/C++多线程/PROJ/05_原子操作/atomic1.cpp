/*
    文件：atomic1.cpp 
    功能：使用原子库取代互斥库实现线程同步
    编译：g++ -Wall -g -std=c++11 -pthread atomic1.cpp -o atomic1
*/

#include <chrono>
#include <atomic>
#include <thread>
#include <iostream> 

std::chrono::milliseconds interval(100);
// 原子布尔类型，取代互斥量
std::atomic<bool> readyFlag(false);    
// 两个线程都能修改'job_shared'，将该变量特化为原子类型 
std::atomic<int> job_shared(0); 
// 只有一个线程能修改'job_exclusive'，不需要保护
int job_exclusive = 0; 

// 此线程只能修改 'job_shared'
void job_1()
{   
    std::this_thread::sleep_for(5 * interval);
    job_shared.fetch_add(1);
    std::cout << "job_1 shared (" << job_shared.load() << ")\n";
    // 改变布尔标记状态为真
    readyFlag.store(true);      
}

// 此线程能修改'job_shared'和'job_exclusive'
void job_2()
{
    // 无限循环，直到可访问并修改"job_shared"
    while (true) 
    {    
        // 判断布尔标记状态是否为真，为真则修改"job_shared"
        if (readyFlag.load()) 
        {   
            
            job_shared.fetch_add(1);
            std::cout << "job_2 shared (" << job_shared.load() << ")\n";
            return;
        } 
        else // 布尔标记为假,则修改"job_exclusive"
        {      
            
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

    return 0;
}
