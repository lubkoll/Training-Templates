#include <chrono>
#include <cmath>
#include <ctime>
#include <functional>
#include <iostream>
#include <random>

// Generate uniformly distributed integer numbers in [low,high].
// Each run of this program will generate the same sequence.
int random_int(int low, int high)
{
    // random number generation engine (seeded with default value)
    std::minstd_rand engine{};
    // random number distribution
    std::uniform_int_distribution<int> distribution {};
    return distribution(engine,
                        std::uniform_int_distribution<int>::param_type{low, high});
}

int main()
{
    std::cout << "uniform_int_distribution" << std::endl;
    for(auto i=0; i<10; ++i)
        std::cout << random_int(42,73) << std::endl;
    std::cout << std::endl;

    std::cout << "normal_distribution (example of Stroustroup)" << std::endl;
    // random number generation engine (seeded with default value)
    std::default_random_engine re;   // the default engine
    // random number distribution
    std::normal_distribution<double> nd(31, // mean
                                        8 // sigma
                                        );

    auto norm = bind(nd, re);

    std::vector<int> mn(64);
    for (int i = 0; i<1200; ++i) ++mn[std::round(norm())]; // generate

    for (int i = 0; i<mn.size(); ++i) {
        std::cout << i << '\t';
        for (int j=0; j<mn[i]; ++j) std::cout << '*';
        std::cout << '\n';
    }
    /**
     * Much more at:
     *  - http://en.cppreference.com/w/cpp/header/random
     *  - http://www.stroustrup.com/C++11FAQ.html#std-random
     */
}
