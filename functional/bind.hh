#pragma once

#include <functional>
#include <iostream>

namespace bind
{
    struct Operation
    {
        int add(int x, int y) const { return x + y; }
    };

    struct NonCopyable
    {
        constexpr NonCopyable() noexcept = default;
        NonCopyable(const NonCopyable&) = delete;
        NonCopyable& operator=(const NonCopyable&) = delete;

        NonCopyable(NonCopyable&&) = default;
        NonCopyable& operator=(NonCopyable&&) = default;
    };

    void example()
    {
    }
}
