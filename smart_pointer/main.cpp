#include <iostream>
#include <stdexcept>
#include <memory>

#include "unique_ptr.hh"
#include "shared_ptr.hh"
#include "weak_ptr.hh"


bool throws()
{
    throw std::runtime_error("hi");
}


int main()
{
    std::cout << std::boolalpha;

    // C++98: raw owning pointers
    try {
        auto char_ptr = new char('c');
        if( throws() )
            delete char_ptr;
        delete char_ptr;
    }
    catch (...) {}
}
