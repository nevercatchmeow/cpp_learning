/*
    文件：future2.cpp
    功能：使用promise传递被调用线程返回结果，通过共享状态变化通知调用线程已获得结果

    编译：g++ -Wall -g -std=c++11 -pthread future2.cpp -o future2
*/

#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <numeric>
#include <vector>
 
void accumulate(std::vector<int>::iterator first,
                std::vector<int>::iterator last,
                std::promise<int> accumulate_promise)
{
    int sum = std::accumulate(first, last, 0);
    // 将结果存入，并让共享状态变为就绪以提醒future
    accumulate_promise.set_value(sum);  
}
 
int main()
{
    // 演示用 promise<int> 在线程间传递结果。
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6 };
    std::promise<int> accumulate_promise;
    std::future<int> accumulate_future = accumulate_promise.get_future();
    std::thread work_thread(accumulate, numbers.begin(), numbers.end(),
                            std::move(accumulate_promise));
    // 等待结果
    accumulate_future.wait();  
    std::cout << "result=" << accumulate_future.get() << '\n';
    // 阻塞等待线程执行完成
    work_thread.join();  
 
    return 0;
}
