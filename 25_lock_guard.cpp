// Use std::lock_guard to avoid scrambled output
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
        try
        {
            // Create an std::lock_guard object
            // This calls mtx.lock()
            std::lock_guard<std::mutex> lck_grd(mtx);

            // Start of critical section
            std::cout << str[0] << str[1] << str[2] << std::endl;

            // Critical section throws an exception
            throw std::exception();
            // End of critical section

            std::this_thread::sleep_for(50ms);
            // Calls ~std::lock_guard
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