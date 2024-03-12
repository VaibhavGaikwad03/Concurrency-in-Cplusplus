#include <iostream>
#include <thread>

int main()
{
    /* Use a lambda expression as the thread's entry point */
    std::thread t([]()
                  { std::cout << "Hello, Lambda Thread!\n"; });

    /* Wait for the thread to complete */
    t.join();

    return 0;
}