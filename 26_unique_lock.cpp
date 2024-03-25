// Use std::unique_lock to avoid scrambled output
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <string>

using namespace std::literals;

std::mutex mtx;

void task(std::string str)
{
    for (int i = 0; i < 5; i++)
    {
        // Create an std::unique_lock object
        // This calls mtx.lock()
        std::unique_lock<std::mutex> unq_lck(mtx);

        // Start of critical section
        std::cout << str[0] << str[1] << str[2] << std::endl;
        // End of critical section

        // Unlock the mutex
        unq_lck.unlock();

        std::this_thread::sleep_for(50ms);
    } // Calls ~std::unique_lock
}

int main()
{
    std::thread t1(task, "abc");
    std::thread t2(task, "xyz");
    std::thread t3(task, "pqr");

    t1.join();
    t2.join();
    t3.join();

    return 0;
}