#pragma once


namespace auto_type_deduction
{
    template <class T>
    void f(T t)
    {}


    template <class T>
    void g(const T& t)
    {}


    template <class T>
    void h(T& t)
    {}


    void example()
    {
        int             i = 1;
        const int      ci = i;
        int&        i_ref = i;
        const int& ci_ref = i;
    }
}


