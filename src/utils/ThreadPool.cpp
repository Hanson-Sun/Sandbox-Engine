#include "ThreadPool.h"
#include <stdio.h>

ThreadPool& ThreadPool::getInstance(std::size_t numThreads)
{
    static ThreadPool instance(numThreads);
    return instance;
}

ThreadPool::~ThreadPool()
{
    stop();
}

int ThreadPool::getPoolSize() const
{
    return threads.size();
}

int ThreadPool::getQueueSize() const
{
    return tasks.size();
}

void ThreadPool::waitUntilEmpty()
{
    std::unique_lock<std::mutex> lock(eventMutex);
    event.wait(lock, [&]
               { return remainingTasks == 0; });
}

ThreadPool::ThreadPool(std::size_t numThreads)
{
    printf("Creating thread pool with %d threads\n", numThreads);
    start(numThreads);
}

void ThreadPool::start(std::size_t numThreads)
{
    for (std::size_t i = 0; i < numThreads; i++)
    {
        threads.emplace_back([&]
                             {
            while (true)
            {
                Task task;
                {
                    std::unique_lock<std::mutex> lock{eventMutex};
                    event.wait(lock, [&] { return stopping || !tasks.empty();});

                    if (stopping && tasks.empty())
                        break;

                    task = std::move(tasks.front());
                    tasks.pop();
                }

                task();
            } 
        });

    }
}

void ThreadPool::stop() noexcept
{
    {
        std::unique_lock<std::mutex> lock{eventMutex};
        stopping = true;
    }
    event.notify_all();

    for (std::thread &thread : threads)
    {
        thread.join();
    }
}