#include <iostream>
#include <thread>
#include <string>

/* Thread entry point */
void fun(std::string &str)
{
    str = "xyz";
}

int main()
{
    std::string str = "abc";

    /* Wrap argument in a call to std::ref() */
    std::thread t(fun, std::ref(str));

    t.join();

    /* Verify that str has been modified */
    std::cout << "str is now " << str << '\n';

    return 0;
}