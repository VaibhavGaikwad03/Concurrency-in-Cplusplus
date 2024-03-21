// Example of starting multiple threads
#include <thread>
#include <iostream>

void hello(int num)
{
    // Add delay
    std::this_thread::sleep_for(std::chrono::seconds(num));
    std::cout << "Hello from Thread: " << num << '\n';
}

int main()
{
    // Start three threads
    std::cout << "Starting three threads...\n";
    std::thread t1(hello, 1);
    std::thread t2(hello, 2);
    std::thread t3(hello, 3);

    // Wait for the threads to finish
    t1.join();
    t2.join();
    t3.join();

    return 0;
}