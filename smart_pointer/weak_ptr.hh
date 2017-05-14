#pragma once

#include <iostream>
#include <memory>

void print_weak_ptr(const std::weak_ptr<char>& ptr)
{
    if( auto shared = ptr.lock() )
        std::cout << "contains " << *shared << std::endl;
    else
        std::cout << "empty" << std::endl;
}

void section_weak_ptr()
{
}
