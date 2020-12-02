#include "test.h"
#include "variadic_templates/variadic_templates.h"
#include "variadic_templates/Tuple.h"
#include "initializer/uniform_init.h"
#include "initializer/initializer_lists.h"
#include "initializer/Array.hpp"
#include "range_based_for_loop/for_each_loop.hh"
#include "new_keywords/Empty.hpp"
#include "initializer/Complex.hh"
#include "Alias_Template/test_template.hpp"
#include "new_keywords/DeclType.h"
#include "Lambdas/Lambdas.hpp"

#include <bitset>
#include <string>
#include <vector>

void execute_test_cases(void)
{
    test_variadic_templates();
    test_initializer();
    test_Array();
    test_for_each_loop();
    test_empty_class_object();
    test_mystl_complex();
    test_new_keywords();
    test_lambdas();

}

void test_variadic_templates(void)
{
    PrintX(7.5, "hello", std::bitset<16>(377), 42);

    std::cout << std::endl << "The below is tuple : \n";
    MySTL::tuple<int, float, std::string> t(41, 6.3, "nico");
    std::cout << t.head() << std::endl;
    std::cout << t.tail().head() << std::endl;
    std::cout << t.tail().tail().head() << std::endl;
}

void test_initializer(void)
{
    print({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

    P p(77, 5);
    P q{77, 5};
    P r{77, 5, -15};
    P s = {77, 5};

    P p1 = {77, 5, -15};
    P p2(77, 5, -15);

    funcp({47, 11});
    funcp({47, 11, 3});
    funcp(P{47, 11});
    funcp(P{47, 11, 3});
    funcp(P(47, 11, 3));

    P p3 {77, 5, 42, 500};
    P p4 = {77, 5, 42, 500};
    P p5 {10};

    apply_initializer_list();
}

void test_for_each_loop(void)
{
    std::cout << "\nPrint out the Fibonacci series: " << std::endl;
    std::vector<unsigned long> fibonacci {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    PrintElements(fibonacci);

    std::vector<std::string> vs;
    // for (const MyStrProc& elem : vs)    /* Error : No viable conversion from string to MyStrProc */
    /* But there exists the implicit conversion MyStrProc(std::string& s), then it can work. */
    {

    }
}

void test_new_keywords(void)
{
    GetTypeOfObject();
}
