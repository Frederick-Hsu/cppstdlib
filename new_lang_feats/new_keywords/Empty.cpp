#include "Empty.hpp"

#include <iostream>

#if defined (COMPILER_GENERATE_DEFAULT)
    Empty::Empty()
    {
        std::cout << "Empty::Empty()\n" << std::endl;
    }

    Empty::Empty(const Empty& rhs)
    {
        std::cout << "Empty::Empty(const Empty& rhs)\n" << std::endl;
    }

    Empty& Empty::operator=(const Empty &rhs)
    {
        std::cout << "Empty& Empty::operator=(const Empty &rhs)\n" << std::endl;
        return *this;
    }

    Empty::~Empty()
    {
        std::cout << "Empty::~Empty()\n" << std::endl;
    }
#endif

void test_empty_class_object(void)
{
    Empty e1;
    Empty e2(e1);
    Empty e3;
    e3 = e1;
}
