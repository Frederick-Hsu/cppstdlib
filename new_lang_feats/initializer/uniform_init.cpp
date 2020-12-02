#include "uniform_init.h"

#include <iostream>
#include <vector>
#include <string>
#include <complex>

void uniform_initialize(void)
{
    int values[] {1, 2, 3, 4, 5, 6};
    std::vector<int> fibonacci {1, 1, 2, 3, 5, 8, 13, 21, 34};
    std::vector<std::string> cities {"Berlin", "New York", "London", "Braunschweig", "Cairo", "Cologne"};
    std::complex<double> c{4.0, 3.0};
}

void print(std::initializer_list<int> vals)
{
    for (auto p = vals.begin(); p != vals.end(); ++p)
    {
        std::cout << *p << "\n";
    }
}

void print(MySTL::Initializer_List<int> vals)
{
    for (auto it = vals.begin(); it != vals.end(); ++it)
    {
        std::cout << *it << "\n";
    }
    std::cout << std::endl;
}
