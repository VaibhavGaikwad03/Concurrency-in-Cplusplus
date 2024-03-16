/* Safely destroying an std::thread object when as exception is thrown (verbose = shabdshaha) */
#include <iostream>
#include <thread>

/* Callable object - thread entry point */
void hello()
{
    std::cout << "Hello, Thread!\n";
}

int main()
{
    /* Create the std::thread object */
    std::thread t(hello);

    try
    {
        /* Code that might throw an exception */
        throw std::exception();

        /* No exception if we got here - call join() as usual */
        t.join();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << '\n';
        t.join(); /* Call join() before t's destructor is called */
    }

    /* Calls ~t() */

    return 0;
}