#include <iostream>
#include <string>
#include <set>
#include <tuple>
#include "tuple_printer.hh"


template<class... Args>
void print(const std::tuple<Args...>& t)
{
    std::cout << "( ";
    TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
    std::cout << ")\n\n";
}


int main()
{
    // Create tuple with its variadic constructor
    std::tuple<int,double,char> tpl{1, 2.5, 'c'};
    std::cout << "tpl" << std::endl;
    print(tpl);
}

