#ifndef THREAD_POOL_HPP
#define THREAD_POOL_HPP

/*
    文件：ThreadPool.hpp
    功能：线程池。
*/

#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include <thread>
#include <mutex>
#include <future>
#include <condition_variable>

// 线程安全任务队列
template <typename T>
class SafeQueue
{
private:
    std::queue<T> _queue;
    std::mutex _mutex;
public:
    SafeQueue() {}
    SafeQueue(SafeQueue&& other) {}
    ~SafeQueue() {}

    bool empty()
    {
        std::unique_lock<std::mutex> lock(_mutex);
        return _queue.empty();
    }

    int size()
    {
        std::unique_lock<std::mutex> lock(_mutex);
        return _queue.size();
    }

    void enqueue(T& t)
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _queue.emplace(t);
    }

    bool dequeue(T& t)
    {
        std::unique_lock<std::mutex> lock(_mutex);
        if (_queue.empty())
        {
            return false;
        }
        t = std::move(_queue.front());
        _queue.pop();
        return true;
    }
};

// 线程池
class ThreadPool
{
private:
    // 线程内置工作类
    class ThreadWorker
    {
    private:
        int _id;
        ThreadPool* _pool;
    public:
        ThreadWorker(ThreadPool* pool, const int id) : _pool(pool), _id(id) {}

        void operator()()
        {
            // 基础函数类func
            std::function<void()> func; 
            // 任务队列元素出队标志
            bool dequeued;  
            // 线程池关闭标志：否
            while (!_pool->_shutdown)
            {
                {
                    std::unique_lock<std::mutex> lock(_pool->_mutex);
                    // 若任务队列为空，则阻塞当前线程
                    if (_pool->_queue.empty())
                    {
                        // 等待条件变量通知时唤醒
                        _pool->_conditional_lock.wait(lock);
                    }
                    // 任务队列元素出队
                    dequeued = _pool->_queue.dequeue(func);
                }
                // 若出队标志：true，执行工作函数
                if (dequeued)
                {
                    func();
                }
            }
        }
    };

    // 线程池关闭标志
    bool _shutdown;    
    // 工作任务队列
    SafeQueue<std::function<void()>> _queue;   
    // 工作线程队列
    std::vector<std::thread> _threads; 
    // 线程休眠互斥锁
    std::mutex _mutex; 
    // 条件变量，使线程休眠或唤醒
    std::condition_variable _conditional_lock; 

public:
    ThreadPool(const int threads = 4) : _threads(std::vector<std::thread>(threads)), _shutdown(false) {}
    ThreadPool(const ThreadPool&) = delete;
    ThreadPool(ThreadPool&&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;
    ThreadPool& operator=(ThreadPool&&) = delete;

    // 声明并分配工作线程，将工作线程放入工作线程队列
    void init()
    {
        for (int i = 0; i < _threads.size(); i++)
        {
            _threads.at(i) = std::thread(ThreadWorker(this, i));
        }
    }

    // 唤醒所有工作线程，并等待所有线程完成工作后关闭线程池
    void shutdown()
    {
        // 线程池关闭标志：是
        _shutdown = true;
        // 唤醒所有工作线程
        _conditional_lock.notify_all();
        for (int i = 0; i < _threads.size(); i++)
        {
            if (_threads.at(i).joinable())
            {
                _threads.at(i).join();
            }
        }
    }

    // 提交函数
    template<typename F, typename... Args>
    auto submit(F&& f, Args &&...args) -> std::future<decltype(f(args...))>
    {
        std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
        auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);
        std::function<void()> warpper_func = [task_ptr]()
        {
            (*task_ptr)();
        };
        _queue.enqueue(warpper_func);
        _conditional_lock.notify_one();
        return task_ptr->get_future();
    }
};

#endif // !THREAD_POOL_HPP
