// A class which is internally synchronized
// The member functions lock a mutex before they access a data member
#include <thread>
#include <mutex>
#include <vector>
#include <iostream>
#include <chrono>

using namespace std::literals;

class Vector
{
    std::mutex mtx;
    std::vector<int> vec;

public:
    void push_back(const int &i)
    {
        mtx.lock();
        // Start of critical section
        vec.push_back(i);
        // End of critical section
        mtx.unlock();
    }

    void print()
    {
        mtx.lock();
        // Start of critical section
        for (auto i : vec)
            std::cout << i << ", ";
        // End of critical section
        mtx.unlock();
    }
};

void func(Vector &vec)
{
    for (int i = 1; i <= 5; i++)
    {
        vec.push_back(i);
        std::this_thread::sleep_for(50ms);
        vec.print();
    }
}

int main()
{
    Vector vec;

    std::thread t1(func, std::ref(vec));
    std::thread t2(func, std::ref(vec));
    std::thread t3(func, std::ref(vec));

    t1.join();
    t2.join();
    t3.join();

    return 0;
}