#include <iostream>
#include <thread>

/* Thread entry point function */
void fun(std::string str)
{
    std::cout << str << '\n';
}

int main()
{
    /* fun() takes a string argument */
    std::thread t(fun, "Hello, Thread!");

    t.join();

    return 0;
}