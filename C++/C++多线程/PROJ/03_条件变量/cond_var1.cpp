/*
    文件：cond_var1.cpp
    功能：用互斥锁实现一个生产者消费者模型

    编译：g++ -Wall -g -std=c++11 -pthread cond_var1.cpp -o cond_var1
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <deque>

// 双端队列标准容器全局变量
std::deque<int> q;
// 互斥锁全局变量
std::mutex mu;

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
        if (!q.empty()) 
        {			
            data = q.back();
            // 数据出队锁保护
            q.pop_back();			
            locker.unlock();
            std::cout << "t2 got a value from t1: " << data << std::endl;
        } 
        else 
        {
            locker.unlock();        
        }
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
