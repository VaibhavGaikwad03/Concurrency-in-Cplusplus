// Example of std::recursive_mutex
#include <iostream>
#include <thread>
#include <mutex>

std::recursive_mutex rmtx;

int bad_factorial(int n)
{
    if (n <= 1)
    {
        std::cout << "Returning " << 1 << '\n';
        return 1;
    }
    // std::lock_guard<std::recursive_mutex> lck_grd(rmtx);
    rmtx.lock();

    // Start of critical section
    int retval = n * bad_factorial(n - 1);
    std::cout << "Returning " << retval << std::endl;
    // End of critical section

    rmtx.unlock();
    return retval;
}

int main()
{
    std::thread t1(bad_factorial, 10);
    std::thread t2(bad_factorial, 11);

    t1.join();
    t2.join();

    return 0;
}