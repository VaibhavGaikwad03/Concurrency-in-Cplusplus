// Unsynchronized threads which make conflicting accesses.
// But where is the shared memory location?
 
#include <thread>
#include <iostream>

void print(std::string str)
{
    // A very artificial way to display a string (hehe)
    for (int i = 0; i < 5; i++)
        std::cout << str[0] << str[1] << str[2] << std::endl;
}

int main()
{
    std::thread t1(print, "abc");
    std::thread t2(print, "def");
    std::thread t3(print, "xyz");

    // Wait for the thread to complete
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
