/*
    文件：future3.cpp
    功能：使用packaged_task传递被调用线程返回结果，通过共享状态变化通知调用线程已获得结果

    编译：g++ -Wall -g -std=c++11 -pthread future3.cpp -o future3
*/

#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <numeric>
#include <vector>
 
int accumulate(std::vector<int>::iterator first,
                std::vector<int>::iterator last)
{
    int sum = std::accumulate(first, last, 0);
    return sum;
}
 
int main()
{
    // 演示用 packaged_task 在线程间传递结果。
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6 };
    std::packaged_task<int(std::vector<int>::iterator, std::vector<int>::iterator)> accumulate_task(accumulate);
    std::future<int> accumulate_future = accumulate_task.get_future();
    std::thread work_thread(std::move(accumulate_task), numbers.begin(), numbers.end());
    // 等待结果
    accumulate_future.wait();  
    std::cout << "result=" << accumulate_future.get() << '\n';
    // 阻塞等待线程执行完成
    work_thread.join();  
 
    return 0;
}
