#include <iostream>
#include <thread>

int main()
{
    /* Use lambda expression as the thread's entry point */
    std::thread t([](int a, int b) /* First argument is lambda expression */
                  { std::cout << "The sum of " << a << " and " << b << " is: " << a + b << '\n'; },
                  2, 3); /* The remaining arguments are passed to the lambda expression */

    t.join();

    return 0;
}