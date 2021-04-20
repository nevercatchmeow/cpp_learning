// Compile: g++ -o main main.cpp -std=c++11 -pthread

#include <iostream>
#include <thread>

void proc(const int &param)
{
    std::cout << "当前为子线程，线程ID = " << std::this_thread::get_id() << " ，线程参数为 " << param << std::endl;
}

int main()
{
    std::cout << "当前为主线程，线程ID = " << std::this_thread::get_id() << std::endl;

    int a = 5445029;
    /*
        创建线程
            参数1：函数名
            参数2：函数的第1个参数
            参数n：函数的第n个参数
    */
    std::thread th(proc, a);
    std::cout << "当前为主线程，子线程th的ID = " << th.get_id() << std::endl;
    // 阻塞主线程，直至子线程执行结束。
    th.join();

    return 0;
}