#include "Rvalue_Reference.hpp"

#include <iostream>
#include <string>
#include <complex>

int foo()
{
    return 5;
}

void assign_to_rvalue(void)
{
    std::string s1("Hello");
    std::string s2("World");

    s1 + s2 = s2;
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;

    std::string() = "My darling";   /* temporary object as an Rvalue */
/*===================================================================*/

    std::complex<int> c1(3, 4);
    std::complex<int> c2(5, 12);

    c1 + c2 = std::complex<int>(15, 16);
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;

    std::complex<int>() = std::complex<int>(20, 40);

/*===================================================================*/

    int x = foo();
    // int* ptr = foo();   /* 函数返回值是一个右值 */
    // foo() = 7;
 }
