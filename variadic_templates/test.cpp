#include "test.hpp"
#include "variadic_templates.hpp"
#include "printf.hpp"
#include "my_algo.hpp"
#include "Tuple/PRINT_TUPLE.hpp"

#include <string>
#include <complex>
#include <bitset>
#include <vector>
#include <cmath>

void execute_test_cases(void)
{
    print_all_arguments();
    simulated_print_format();
    test_my_algorithms();
    test_print_tuple();
}

void print_all_arguments(void)
{
    PrintX(7.5,
           "Hello",
           std::bitset<16>(377),
           43,
           std::string("Bjarne Stroustrup"),
           std::vector<int>({1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89}),
           std::complex<float>(3.0, 4.0));
}

void simulated_print_format(void)
{
    int* pnum = new int{10};
    MySTL::printf("%d, %s, %p, %f\n", 15, "This is Frederique Hsu", pnum, "3.1415926");
    delete pnum;
}

void test_print_tuple(void)
{
    std::cout << std::make_tuple(7.5,
                                 std::string("Hello_tuple"),
                                 std::bitset<16>(377),
                                 43)
              << std::endl;
}
