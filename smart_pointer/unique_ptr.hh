#pragma once

#include <chrono>
#include <memory>

struct ThrowsInConstructor
{
    ThrowsInConstructor()
    {
        if( std::rand() > 0)
            throw std::runtime_error("hello");
    }
};

void process_2_ptrs(std::unique_ptr<ThrowsInConstructor> lhs, std::unique_ptr<ThrowsInConstructor> rhs)
{}

void section_unique_ptr()
{

}
