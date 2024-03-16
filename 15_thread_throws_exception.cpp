#include <iostream>
#include <thread>

/* Task function */
void hello()
{
    try
    {
        /* Throw an exception */
        throw std::exception();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << '\n';
    }
    std::cout << "Hello, Thread!\n";
}

int main()
{
    /* Create an std::thread object */
    std::thread t(hello);
    t.join();

    /* Check that the program is still running */
    std::cout << "Finished\n";

    return 0;
}