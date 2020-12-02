#include "initializer_lists.h"

#include <iostream>
#include <vector>
#include <algorithm>

P::P(int a, int b)
{
    std::cout << "P::P(int, int), a = " << a << ", b = " << b << std::endl;
}

P::P(std::initializer_list<int> initlist)
{
    std::cout << "P::P(initializer_list<int>), values = ";
    for (auto i : initlist)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

P::P(int a, int b, int c)
{
#if (CONVERSION == IMPLICIT)
    std::cout << "P::P(int a, int b, int c) \n"
#elif (CONVERSION == EXPLICIT)
    std::cout << "explicit P::P(int a, int b, int c) \n"
#endif
              << "a = " << a << "\n"
              << "b = " << b << std::endl
              << "c = " << c
              << std::endl;
}

void funcp(const P&)
{
}

void apply_initializer_list(void)
{
    std::vector<int> v1 {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    std::vector<int> v2({1, 1, 2, 3, 5, 8, 13, 21, 34, 55});
    std::vector<int> v3;
    v3 = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    v3.insert(v3.begin() + 3, {-1, -2, -3, -4, -5});

    for (auto& elem : v3)
    {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;

    /* by using the global functions std::begin(), std:;end() can accept the container object. */
    for (auto it = std::begin(v3); it != std::end(v3); ++it)
    {
        std::cout << *it << ", \t";
    }
    std::cout << std::endl;

    std::cout << std::max({std::string("Ace"), std::string("Stacy"), std::string("Sabrina"), std::string("Berkley")}) << std::endl;
    std::cout << std::min({std::string("Ace"), std::string("Stacy"), std::string("Sabrina"), std::string("Berkley")}) << std::endl;
    std::cout << std::min({4, 9, -9, 15, 32, -20, 105, -86, 90, 250, 1024}) << std::endl;
}
