/*
    文件：thread1.cpp
    功能：创建线程，并观察线程的并发执行与阻塞等待

    编译：g++ -Wall -g -std=c++11 -pthread thread1.cpp -o thread1		
*/
  
#include <iostream>
#include <thread>
#include <chrono>
 
// 可调用对象：函数
void thread_function(int n)
{
    // 获取线程ID
    std::thread::id this_id = std::this_thread::get_id();			

    for(int i = 0; i < 5; i++){    
        std::cout << "Child function thread " << this_id<< " running : " << i+1 << std::endl;
        // 进程睡眠n秒
        std::this_thread::sleep_for(std::chrono::seconds(n));   	
    }
}

// 可调用对象：仿函数
class Thread_functor
{
public:
    void operator()(int n)
    {
        std::thread::id this_id = std::this_thread::get_id();

        for(int i = 0; i < 5; i++){
            std::cout << "Child functor thread " << this_id << " running: " << i+1 << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(n));   
        }
    }	
};
 
int main()
{
    // 通过 可调用对象-函数 构造。
    std::thread mythread1(thread_function, 1);
    // 判断是否mythread1是否关联线程
    if(mythread1.joinable())
    {
        // 合并线程：阻塞主线程等待mythread1关联的线程完成工作。
        mythread1.join(); 
    }
    
    // 通过 可调用对象-仿函数 构造。
    Thread_functor thread_functor;
    std::thread mythread2(thread_functor, 3);
    if(mythread2.joinable())
    {
        // 分离线程：使子线程和主线程并行运行，主线程不再等待子线程。
        mythread2.detach();
    }                         

    // 可调用对象：Lambda表达式
    auto thread_lambda = [](int n){
        std::thread::id this_id = std::this_thread::get_id();
        for(int i = 0; i < 5; i++)
        {
            std::cout << "Child lambda thread " << this_id << " running: " << i+1 << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(n));   
        }       
    };

    // 通过 可调用对象-Lambda表达式 构造。
    std::thread mythread3(thread_lambda, 4);     
    if(mythread3.joinable())
    {
        mythread3.join();
    }

    // 获取主线程ID
    std::thread::id this_id = std::this_thread::get_id();
    for(int i = 0; i < 5; i++){
        std::cout << "Main thread " << this_id << " running: " << i+1 << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
#ifdef WIN32
    system("pause");
#endif
    return 0;
}
