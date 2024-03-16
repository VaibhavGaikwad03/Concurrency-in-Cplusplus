/* What happen to an std::thread object when an exception is thrown? */
#include <iostream>
#include <thread>

/* Callable object - thread entry point */
void hello()
{
    std::cout << "Hello, Thread!\n";
}

int main()
{
    try
    {
        /* Create the std::thread object */
        std::thread t(hello);

        /* Code that might throw an exception */
        throw std::exception();

        t.join();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << '\n';
    }

    return 0;
}