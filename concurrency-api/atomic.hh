#pragma once

#include <atomic>
#include <functional>
#include <future>
#include <iostream>

namespace atomic
{
    void write_hello()
    {
        std::cout << "hello" << std::endl;
    }

    void count_executions_in_all_threads(std::atomic<int>& counter,
                                         std::function<void()> f)
    {
        f();
        ++counter;
    }

    void example()
    {
    }
}
