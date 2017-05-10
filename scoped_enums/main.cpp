#include <iostream>

using std::cout;
using std::endl;


enum ErrorCode { NO_ERROR=1, FATAL_ERROR };

int main()
{
    auto error = ErrorCode();
    int value = error;
    cout << error << endl;

/*
    // error codes with the google test framework:
    // functions for which mocking is not specified provide default-constructed return values
*/
}
