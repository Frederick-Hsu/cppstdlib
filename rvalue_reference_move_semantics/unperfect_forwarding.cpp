#include "unperfect_forwarding.hpp"

#include <iostream>

void process(int& i)
{
    std::cout << "process(int&): Lvalue = " << i << std::endl;
}

void process(int&& i)
{
    std::cout << "process(int&&): Rvalue = " << i << std::endl;
}

void forward(int&& i)
{
    std::cout << "forward(int&&): Rvalue = " << i << ", ";
    process(i);
}

void test_unperfect_forward(void)
{
    int a = 0;      /* a is a variable, variable is the Lvalue */

    process(a);
    process(1);     /* constant number is a Rvalue */
    process(std::move(a));  /* move() function converts variable Lvalue to Rvalue */

    forward(2);         /* Rvalue 经由 forward(int&&) 传递给另一个函数却变成了 Lvalue
                         * 原因是传递过程中它变成了一个 named object
                         */
    forward(std::move(a));      /* Rvalue 经由forward(int&&)传递给另外一个函数却变成了 Lvalue */

    // forward(a);     /* Error: cannot bind 'int' Lvalue to 'int&&' Rvalue */

    const int& b = 1;
    // process(b);     /* Error: no matching function for call to 'process(const int&)' */

    /* Error: no matching function for call to 'process(std::remove_reference<const int&>::type)' */
    // process(std::move(b));

    /* Error: invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int' */
    // int& x(5);
    // process(std::move(x));
}
