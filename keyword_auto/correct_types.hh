#pragma once

#include <iostream>
#include <map>
#include <type_traits>
#include <vector>

void use_correct_types()
{
    using std::cout;
    using std::endl;

    // auto helps in avoiding usage of wrong types that support implicit conversion
    std::vector<int> vec;
    int size = vec.size();

    cout << "std::is_same<int, decltype(vec.size())>::value = "
         << std::is_same<int, decltype(vec.size())>::value << endl;
}
