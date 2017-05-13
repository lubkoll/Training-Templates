#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace std::chrono;

int main()
{
    vector<string> v;
    const string start_of_lorem_ipsum = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed pellentesque consequat purus ut fringilla. Morbi pharetra odio purus, eu viverra leo accumsan non. Vivamus nec metus nec nibh faucibus commodo. Aliquam quis ipsum egestas ante facilisis rhoncus ut nec nisi. Nulla quis tortor imperdiet, varius nibh nec, egestas nulla. Nullam porttitor interdum lacinia. Sed cursus eros a tortor malesuada, id commodo nunc condimentum. Suspendisse vel lacinia erat. Nunc malesuada sapien eu erat venenatis, ut laoreet justo congue. Suspendisse eu lacus ante. Cras vel tempor ligula.";

    constexpr auto n = 1'000'000;

    auto start_time = system_clock::now();

    for(auto i=0; i<n; ++i)
        v.push_back(start_of_lorem_ipsum);
}
