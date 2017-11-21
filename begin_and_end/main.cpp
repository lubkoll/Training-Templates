#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>


std::vector<int> create_vector()
{
    return { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
}

namespace project1
{
    struct Vector
    {
        template <class... Args,
                  std::enable_if_t<
                      std::is_constructible< std::vector<int>, Args... >::value &&
                      !std::is_constructible< Vector, Args... >::value
                   >* = nullptr>
        explicit Vector(Args&&... args)
            : data(std::forward<Args>(args)...)
        {}

        std::vector<int> data;
    };
/*
    auto begin(Vector& v) -> decltype(begin(v.data))
    {
        return begin(v.data);
    }

    auto end(Vector& v) -> decltype(end(v.data))
    {
        return end(v.data);
    }
*/
    Vector create_vector()
    {
        return Vector(::create_vector());
    }
}

namespace project2
{
    struct Vector
    {
        template <class... Args,
                  std::enable_if_t<
                      std::is_constructible< std::vector<int>, Args... >::value &&
                      !std::is_constructible< Vector, Args... >::value
                  >* = nullptr>
        explicit Vector(Args&&... args)
            : data(std::forward<Args>(args)...)
        {}

        auto begin()
        {
            return data.begin();
        }

        auto end()
        {
            return data.end();
        }

        std::vector<int> data;
    };

    Vector create_vector()
    {
        return Vector(::create_vector());
    }
}


int main()
{
    auto printer = [](const auto& i) { std::cout << i << ' '; };

    //    int v[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    auto v = create_vector();

    std::for_each( v.begin(), v.end(), printer );
    std::cout << '\n';

    std::sort( v.begin(), v.end() );

    std::for_each( v.begin(), v.end(), printer );
    std::cout << '\n';
}
