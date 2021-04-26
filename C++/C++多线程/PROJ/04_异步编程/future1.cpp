/*
    文件：future1.cpp
    功能：使用全局变量传递被调用线程返回的结果，使用条件变量通知调用线程已获得结果

    编译：g++ -Wall -g -std=c++11 -pthread future1.cpp -o future1
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <vector>
#include <numeric>

// 保存结果的全局变量
int res = 0;	
// 互斥锁全局变量					
std::mutex mu;	
// 全局条件变量					
std::condition_variable cond;       
 
void accumulate(std::vector<int>::iterator first,
                std::vector<int>::iterator last)
{
    // 标准库求和函数
    int sum = std::accumulate(first, last, 0);      
    std::unique_lock<std::mutex> locker(mu);
    res = sum;
    locker.unlock();
     // 向一个等待线程发出"条件已满足"的通知
    cond.notify_one();             
}
 
int main()
{
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6 };
    std::thread work_thread(accumulate, numbers.begin(), numbers.end());

    std::unique_lock<std::mutex> locker(mu);
    // 如果条件变量被唤醒，检查结果是否被改变，为真则直接返回，为假则继续等待
    cond.wait(locker, [](){ return res;});   
    std::cout << "result=" << res << '\n';
    locker.unlock();
    // 阻塞等待线程执行完成
    work_thread.join();         
 
    getchar();
    return 0;
}
