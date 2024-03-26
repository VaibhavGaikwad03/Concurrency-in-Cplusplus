// Example of std::unique_lock's try_lock_for() member function
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std::literals;

std::timed_mutex tmtx;
 
void task1()
{
    std::cout << "Task1 trying to lock the mutex\n";
    std::lock_guard<std::timed_mutex> lck_grd(tmtx);
    std::cout << "Task1 locks the mutex\n";
    std::this_thread::sleep_for(5s);
    std::cout << "Task1 unlocking the mutex\n";
}

void task2()
{
    std::this_thread::sleep_for(500ms);
    std::cout << "Task2 trying to lock the mutex\n";

    std::unique_lock<std::timed_mutex> unq_lck(tmtx, std::defer_lock);

    // Try for 1 second to lock the mutex
    while (!unq_lck.try_lock_for(1s))
    {
        // Returned false
        std::cout << "Task2 could not lock the mutex\n";
        // Try again on the next iteration
    }

    // Returned true - the mutex is now locked

    // Start of critical section
    std::cout << "Task2 has locked the mutex\n";
    // End of critical section
}

int main()
{
    std::thread t1(task1);
    std::thread t2(task2);

    t1.join();
    t2.join();

    return 0;
}
