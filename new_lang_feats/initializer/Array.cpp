#include "Array.hpp"

#include <iostream>

void test_Array(void)
{
    MySTL::Array<int, 10> myArray {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    auto it = myArray.begin();
    it += 3;
    std::cout << *it << std::endl;
}
