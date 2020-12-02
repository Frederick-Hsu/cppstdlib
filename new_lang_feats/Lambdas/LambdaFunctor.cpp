#include "LambdaFunctor.hpp"

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

#define PREDICATE_LAMBDA    1
#define PREDICATE_FUNCTOR   2
#define PREDICATE           PREDICATE_LAMBDA

LambdaFunctor::LambdaFunctor(int lower, int upper) : m_lower(lower), m_upper(upper)
{
}

bool LambdaFunctor::operator()(int n) const
{
    return ((m_lower < n) && (n < m_upper));
}

void apply_lambda_as_compare_predicate(void)
{
    std::vector<int> numbers {5, 28, 50, 83, 70, 590, 245, 59, 24};
    int lower = 30;
    int upper = 100;
    numbers.erase(std::remove_if(numbers.begin(),
                                 numbers.end(),
                             #if (PREDICATE == PREDICATE_LAMBDA)
                                 [lower, upper](int n) { return ((lower < n) && (n < upper)); }
                             #elif (PREDICATE == PREDICATE_FUNCTOR)
                                 LambdaFunctor(lower, upper)
                             #endif
                                ),
                  numbers.end());
    for (auto& elem : numbers)
    {
        std::cout << elem << ",\t";
    }
    std::cout << std::endl;
}
