// Use std::lock_guard to avoid scrambled output
// Find out what happens when as exception is thrown
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <string>

using namespace std::literals;

std::mutex mtx;

void task(const std::string &str)
{
    for (int i = 0; i < 5; i++)
    {
        try
        { // Lock the mutex before the critical section
            mtx.lock();

            // Start of critical section
            std::cout << str[0] << str[1] << str[2] << std::endl;

            // Critical section throws an exception
            throw std::exception();
            // End of critical section

            // Never gets called
            mtx.unlock();
            std::this_thread::sleep_for(50ms);
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << '\n';
        }
    }
}

int main()
{
    std::thread t1(task, "abc");
    std::thread t2(task, "xyz");
    std::thread t3(task, "pqr");

    t1.join();
    t2.join();
    t3.join();
}