// Use mutex to avoid scrambled output
#include <iostream>
#include <mutex>
#include <thread>
#include <string>

// Global mutex object
std::mutex mtx;

void task(const std::string &str)
{
    for (int i = 0; i < 5; i++)
    {
        mtx.lock(); // Lock the mutex before critical section

        // Start of critical section
        std::cout << str[0] << str[1] << str[2] << std::endl;
        // End of critical section

        mtx.unlock(); // Unlock the mutex after critical section
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

    return 0;
}