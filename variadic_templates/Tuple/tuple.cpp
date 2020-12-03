#include "tuple.hpp"
#include "tup.hpp"
#include "PRINT_TUPLE.hpp"

#include <string>
#include <complex>
#include <bitset>

void test_user_implemented_tuple(void)
{
    MySTL::tuple<int, float, std::string> tpl(41, 6.3, "Frederique");

    std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
    std::cout << "sizeof(float) = " << sizeof(float) << std::endl;
    std::cout << "sizeof(std::string) = " << sizeof(std::string) << std::endl;
    std::cout << "sizeof(std::string(\"Frederique\")) = " << sizeof(std::string("Frederique")) << std::endl;
    std::cout << "sizeof(tpl) = " << sizeof(tpl) << std::endl;
    std::cout << tpl.head() << std::endl;
    std::cout << tpl.tail().head() << std::endl;
    std::cout << tpl.tail().tail().head() << std::endl;
}

void test_composited_tup(void)
{
    MySTL::tup<int, float, std::string> tupl1(41, 6.3, "Nicolas");
    std::cout << "sizeof(tupl1) = " << sizeof(tupl1) << std::endl;
    std::cout << tupl1.head() << std::endl;
    std::cout << tupl1.tail().head() << std::endl;
    std::cout << tupl1.tail().tail().head() << std::endl;

    MySTL::tup<std::string, std::complex<int>, std::bitset<16>, double> tupl2("Alice Yu",
                                                                              std::complex<int>(3, 4),
                                                                              std::bitset<16>(377),
                                                                              3.1415926);
    std::cout << "sizeof(tupl2) = " << sizeof(tupl2) << std::endl;
    std::cout << tupl2.head() << std::endl;
    std::cout << tupl2.tail().head() << std::endl;
    std::cout << tupl2.tail().tail().head() << std::endl;
    std::cout << tupl2.tail().tail().tail().head() << std::endl;
}
