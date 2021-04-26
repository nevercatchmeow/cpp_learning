/*
    文件：future4.cpp
    功能：使用async传递被调用线程返回结果
    编译：g++ -Wall -g -std=c++11 -pthread future4.cpp -o future4
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
    // 演示用 async 在线程间传递结果。
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6 };
    // auto可以自动推断变量的类型
    auto accumulate_future = std::async(std::launch::async, accumulate, numbers.begin(), numbers.end());		
    std::cout << "result=" << accumulate_future.get() << '\n';
    
    return 0;
}
