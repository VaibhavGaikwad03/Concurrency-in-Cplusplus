#include <iostream>
#include <thread>

/* The task function */
void hello()
{
    using namespace std::literals;
    std::this_thread::sleep_for(1s);
    std::cout << "Hello, Thread!\n";
}

/* Function taking a thread object as argument */
/* The object must be moved to argument */

void func(std::thread t)
{
    std::cout << "Received thread with ID: " << t.get_id() << '\n';

    /* The function argument now owns the system thread */
    /* It is responsibility for calling join() */
    t.join();
}

int main()
{
    /* std::thread is a move only object */
    std::thread t(hello);

    /* Display the child thread's ID */
    std::cout << "Hello thread has ID: " << t.get_id() << '\n';

    /* Pass a named object using std::move() */
    func(std::move(t));

    /* Pass a temporary object */
    /* func(std::thread(hello)); */

    return 0;
}