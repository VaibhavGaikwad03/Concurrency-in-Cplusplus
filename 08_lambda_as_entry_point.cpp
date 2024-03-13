#include <iostream>
#include <thread>

int main()
{
    int i = 3;

    /* Use lambda expression as the thread's entry point */
    std::thread t([&i] /* First argument is lambda expression */
                  { i *= 2; });

    t.join();

    std::cout << "Value of i is now: " << i << '\n';

    return 0;
}