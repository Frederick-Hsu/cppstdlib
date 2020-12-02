#include <iostream>

#include "test.h"

using namespace std;

int main()
{
    cout << "Current C++ standard no.: " << __cplusplus << endl;

    execute_test_cases();
    return 0;
}
