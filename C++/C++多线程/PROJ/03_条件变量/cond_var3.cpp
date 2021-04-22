/*
    文件：cond_var3.cpp
    功能：用互斥锁实现一个生产者消费者模型（优化版：使用条件变量）

    编译：g++ -Wall -g -std=c++11 -pthread cond_var3.cpp -o cond_var3
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>

// 双端队列标准容器全局变量
std::deque<int> q;
// 互斥锁全局变量
std::mutex mu;
// 条件变量全局变量
std::condition_variable cond;

// 生产者：向队列放入数据
void function_1() 
{
    int count = 10;
    while (count > 0) 
    {
        std::unique_lock<std::mutex> locker(mu);
        // 数据入队锁保护
        q.push_front(count);			
        locker.unlock();
        // 向一个等待线程发出"条件已满足"通知
        cond.notify_one();
        // 延时1秒
        std::this_thread::sleep_for(std::chrono::seconds(1));		
        count--;
    }
}
// 消费者：从队列提取数据
void function_2() 
{
    int data = 0;
    while ( data != 1) 
    {
        std::unique_lock<std::mutex> locker(mu);
        //  判断队列是否为空
        while (q.empty()) 
        {
            // 解锁互斥量并陷入休眠等待通知到达被唤醒，唤醒后对互斥量加锁
            cond.wait(locker);
        }
	
        data = q.back();
        // 数据出队锁保护
        q.pop_back();			
        locker.unlock();
        std::cout << "t2 got a value from t1: " << data << std::endl;
    }
}

int main() 
{
    std::thread t1(function_1);
    std::thread t2(function_2);
    t1.join();
    t2.join();

    getchar();
    return 0;
}
