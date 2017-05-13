#pragma once

#include <functional>
#include <iostream>

namespace function
{
    void invoke(const std::function<const char*()>& f)
    {
        std::cout << ( f ? f() : "empty function"  ) << "\n";
    }

    struct T
    {
        void operator()(int new_value)
        {
            value = new_value;
        }

        int value = 0;
    };

    void example()
    {
        std::function<const char*()> f;
    }
}
