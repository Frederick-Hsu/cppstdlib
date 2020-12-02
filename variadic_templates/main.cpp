#include <iostream>

#include "test.hpp"

using namespace std;

int main()
{
    cout << "Current C++ standard no. = " << __cplusplus << endl;

    cout << "Current program is " << sizeof(void*) * 8 << "-bit" << endl;

    execute_test_cases();
    return 0;
}
