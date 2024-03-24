// Example of calling try_lock() in a loop until the mutex is locked
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std::literals;

std::mutex mtx;

void task1()
{
    std::cout << "Task1 trying to lock the mutex" << std::endl;
    mtx.lock();
    std::cout << "Task1 has locked the mutex" << std::endl;
    std::this_thread::sleep_for(500ms);
    std::cout << "Task1 unlocking the mutex" << std::endl;
    mtx.unlock();
}

void task2()
{
    std::this_thread::sleep_for(100ms);
    std::cout << "Task2 trying to lock the mutex" << std::endl;
    while (!mtx.try_lock())
    {
        std::cout << "Task2 could not lock the mutex" << std::endl;
        std::this_thread::sleep_for(100ms);
    }
    std::cout << "Task2 has locked the mutex" << std::endl;
    mtx.unlock();
}

int main()
{
    std::thread t1(task1);
    std::thread t2(task2);

    t1.join();
    t2.join();

    return 0;
}