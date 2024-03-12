#include <iostream>
#include <thread>

/* Callable object - thread entry point */
void fun()
{
    std::cout << "Hello, Thread!\n";
}

int main()
{
    /* Create an std::thread */
    std::thread t(fun); /* Pass the entry point function to the constructor */

    t.join(); /* Wait for the thread to complete */

    return 0;
}