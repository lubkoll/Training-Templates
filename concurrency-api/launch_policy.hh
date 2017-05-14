#pragma once

#include <functional>
#include <future>
#include <iostream>

namespace launch_policy
{
    void write_hello()
    {
        std::cout << "hello" << std::endl;
    }

    auto count_executions_in_separate_threads(std::function<void()> f)
    {
        thread_local int counter = 0;
        f();
        return ++counter;
    }

    void example()
    {
    }
}
