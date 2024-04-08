#pragma once
#include <vector>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <algorithm>
#include <atomic>
#include <queue>

/**
 * @brief A threadPool class that holds a list of threads and a queue of task.
 */
class ThreadPool
{
public:
    // basic function wrapper
    using Task = std::function<void()>;

    // Static method to get the single instance of the class
    static ThreadPool& getInstance(std::size_t numThreads = std::thread::hardware_concurrency());

    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;

    /**
     * @brief Destroy the Thread Pool object
     */
    ~ThreadPool();

    /**
     * @brief Get the Pool Size object
     *
     * @return int
     */
    int getPoolSize() const;

    /**
     * @brief Get the number of tasks in queue
     *
     * @return int
     */
    int getQueueSize() const;

    // im gonna be real honest, i barely know how this works
    /**
     * @brief adds a task to the queue for processes by the threads
     *
     * @tparam T generic class
     * @param task generic task (some type of function)
     * @return std::future<decltype(task())> whatever value the task returns when it completes
     */
    template <class T>
    void enqueue(T task)
    {
        {
            std::unique_lock<std::mutex> lock{eventMutex};
            tasks.emplace(task);
        }

        event.notify_one();
    }

    void waitUntilEmpty();

private:
    // the "pool" of threads
    std::vector<std::thread> threads;
    /**
    synchronization primitive that allows threads to wait until a certain condition is satisfied.
    It enables "wait and notify" behavior between threads, where one or multiple
    threads can be blocked until another thread sends a notification.
        */
    std::condition_variable event;
    std::mutex eventMutex;
    bool stopping = false;

    std::queue<Task> tasks;
    std::atomic<int> remainingTasks;

    /**
     * @brief Construct a new Thread Pool object
     *
     * @param numThreads number of threads that the thread pool contains
     */
    explicit ThreadPool(std::size_t numThreads);

    /**
     * @brief initialize the threads
     *
     * @param numThreads
     */
    void start(std::size_t numThreads);

    /**
     * @brief stops all the threads in the thread pool
     */
    void stop() noexcept;
};