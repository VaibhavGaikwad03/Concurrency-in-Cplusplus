#include <iostream>
#include <thread>

/* Functor class with overloaded () operator */
class demo
{
public:
    void operator()()
    {
        std::cout << "Hello, Functor Thread!\n";
    }
};

int main()
{
    /* Create an object of functor class */
    demo fun;

    /* Pass the functor object to std::thread's constructor */
    std::thread t(fun);

    /* Wait for the thread to complete */
    t.join();

    return 0;
}