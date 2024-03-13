#include <iostream>
#include <thread>

/* Class whose member function will be used as the thread's entry point */
class Demo
{
public:
    void hello()
    {
        std::cout << "Hello, Member funtion thread!\n";
    }
};

int main()
{
    Demo obj;

    /* Create the std::thread object */
    /* Pass a pointer to a member function */
    /* and pointer to the object to call it on */
    std::thread t(&Demo::hello, &obj);

    t.join();

    return 0;
}