#include <iostream>
#include <thread>

/* The task function */
void hello()
{
    std::cout << "Hello, Thread!\n";
}

/* Function returning std::thread object */
std::thread func()
{
    /* Start the thread */
    std::thread t(hello);

    /* Return local variable */
    return t;

    // return std::move(t);    // Not error
}

int main()
{
    /* Call a function which returns std::thread object */
    std::thread t = func();
    std::cout << "Received thread with ID: " << t.get_id() << '\n';

    /* Our t object now owns the system thread */
    /* It is responsible for calling join() */
    t.join();

    return 0;
}