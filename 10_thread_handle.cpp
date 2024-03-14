#include <iostream>
#include <thread>

/* Task funtion */
void hello()
{
    std::cout << "Hello, World!" << std::endl;
}

int main()
{
    /* Create an std::thread object */
    std::thread t(hello);

    /* Display the child thread's native handle */
    std::cout << "Hello thread has native handle " << t.native_handle() << '\n';

    /* Wait for the thread to complete */
    t.join();

    /* Display the child thread's native handle again */
    std::cout << "Hello thread now has native handle " << t.native_handle() << '\n';

    return 0;
}