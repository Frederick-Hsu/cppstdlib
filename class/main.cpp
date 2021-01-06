/* File name    : main.cpp
 *
 */

#include <iostream>

#include "Date.hpp"
#include "Test.h"

int main(int argc, char* argv[])
{
    std::cout << "Current C++ standard no. = " << __cplusplus << std::endl;
    std::cout << "Current program is " << sizeof(void*) * 8 << "-bit.\n" << std::endl;

    // Date today(3, 1, 2021);
    // Date xmas(25, 12, 2020);
    perform_test_cases();

    return 0;
}