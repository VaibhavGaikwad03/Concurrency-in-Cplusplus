#include <iostream>
#include <thread>

/* Task funtion */
void hello()
{
    std::cout << "Hello, World!\n";
}

int main()
{
    /* Create an std::thread object */
    std::thread t(hello);

    /* Display the child thread's native handle */
    std::cout << "Hello thread has native handle " << t.native_handle() << '\n';

    /* Wait for the thread to complete */
    t.join();

    return 0;
}