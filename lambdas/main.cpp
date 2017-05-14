#include <algorithm>
#include <functional>
#include <iostream>
#include <tuple>
#include <vector>

auto get_add_to_offset_bad()
{
    int offset = 3;
    // Captures local variable by reference
    // -> reference will dangle
    return [&offset] (int i) { return offset + i; };
}

auto get_add_to_offset_worse()
{
    int offset = 3;
    // Captures all variables by reference
    // -> in more complex situations we don't even know which references might dangle
    return [&] (int i) { return offset + i; };
}

auto get_add_to_offset_good()
{
    int offset = 3;
    // Captures local variable by value
    return [offset] (int i) { return offset + i; };
}

auto get_add_to_offset_bad2()
{
    int offset = 3;
    // Captures local variable by value
    // Safe here, but may be unsafe in other use-cases
    return [=] (int i) { return offset + i; };
}

auto get_add_to_offset_bad3()
{
    static int offset = 3;
    auto lambda = [=](int i) { return offset + i; };
    offset++;
    return lambda;
}


struct AddToOffset
{
    auto get() const
    {
        // Here offset can not be captured, since it is a member variable.
        // Instead 'this' gets captured by value
        // -> 'this' may dangle
        return [=] (int i) { return offset + i; };
    }

private:
    int offset = 3;
};

struct IsOdd
{
    int operator()(int i)
    {
        return i%2;
    }
};


int main()
{
    std::vector<int> v = { 1, 2, 3, 4, 5 };

    std::cout << "C++98/03:" << std::endl;
    auto odd_elements = count_if( begin(v), end(v),
                                  IsOdd() );
    std::cout << "odd_elements: " << odd_elements << "\n\n";
}
