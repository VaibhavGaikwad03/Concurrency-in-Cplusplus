#include <iostream>
#include <thread>

class thread_guard
{
    std::thread t;

public:
    /* Constructor takes an rvalue refernce argument (std::thread is move-only) */
    explicit thread_guard(std::thread &&thr) : t(std::move(thr)) {}

    /* Destructor - join the thread if necessary */
    ~thread_guard()
    {
        if (t.joinable())
            t.join();
    }

    thread_guard(const thread_guard &) = delete; // Deleted copy operators to prevent copy
    thread_guard &operator=(const thread_guard &) = delete;
};

void hello()
{
    std::cout << "Hello, Thread!\n";
}

int main()
{
    try
    {
        std::thread t(hello);
        thread_guard tguard(std::move(t));
        // thread_guard tguard{std::move(t)};   both allowed

        // Code which might throw an exception
        throw std::exception();
    } // Calls ~thread_guard followed by ~thread
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << '\n';
    }

    return 0;
}