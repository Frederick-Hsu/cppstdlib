#include "tuple.hpp"
#include "PRINT_TUPLE.hpp"

#include <string>

void test_user_implemented_tuple(void)
{
    MySTL::tuple<int, float, std::string> tpl(41, 6.3, "Frederique");
    std::cout << tpl.head() << std::endl;
    std::cout << tpl.tail().head() << std::endl;
    std::cout << tpl.tail().tail().head() << std::endl;
}
