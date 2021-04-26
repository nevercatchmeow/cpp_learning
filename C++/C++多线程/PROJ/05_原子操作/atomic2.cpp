/*
    文件：atomic2.cpp 
    功能：使用原子布尔类型实现自旋锁的功能
    编译：g++ -Wall -g -std=c++11 -pthread atomic2.cpp -o atomic2
*/

#include <thread>
#include <vector>
#include <iostream>
#include <atomic>

// 初始化原子布尔类型
std::atomic_flag lock = ATOMIC_FLAG_INIT;       
 
void f(int n)
{
    for (int cnt = 0; cnt < 100; ++cnt) 
    {
        // 获得锁
        while (lock.test_and_set(std::memory_order_acquire)); // 自旋
        std::cout << n << " thread Output: " << cnt << '\n';
        // 释放锁
        lock.clear(std::memory_order_release);
    }
}
 
int main()
{
    // 实例化一个元素类型为std::thread的向量
    std::vector<std::thread> v;     
    for (int n = 0; n < 10; ++n) 
    {
        // 以参数(f,n)为初值的元素放到向量末尾，相当于启动新线程f(n)
        v.emplace_back(f, n);       
    }
    for (auto& t : v) 
    {     
        // 遍历向量v中的元素，基于范围的for循环，auto&自动推导变量类型并引用指针指向的内容
        t.join();   // 阻塞主线程直至子线程执行完毕
    }

    return 0;
}
