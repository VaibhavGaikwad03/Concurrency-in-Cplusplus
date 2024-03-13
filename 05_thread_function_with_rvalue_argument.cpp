#include <iostream>
#include <thread>
#include <string>

/* Thread entry point function */
void fun(std::string &&str) /* Requires a rvalue argument */
{
    std::cout << "Ownership of \"" << str << "\" transferred to thread" << '\n';
}

int main()
{
    std::string str = "moveable";
    std::cout << "Starting thread\n";

    /* Wrap str in a call to std::move() */
    std::thread t(fun, std::move(str));

    t.join();

    /* Verify that str has been modified */
    std::cout << "Do you still have any data? ";
    std::cout << (str.empty() ? "No" : "Yes") << ".\n";

    return 0;
}