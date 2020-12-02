#include "Lambdas.hpp"
#include "Functor.hpp"

#include <iostream>

static void define_call_lambdas(void);

void test_lambdas(void)
{
    define_call_lambdas();
    // test_functor();
    lambda_expression1();
    lambda_expression2();
    lambda_expression3();
    lambda_expression4();
}

/* The form of lambda function:

  [...](...) mutable throwSpec -> retType
  {
       ...
  };

 */

auto lambda = []
{
    std::cout << "Hello, Lambda anonymous function." << std::endl;
};

void define_call_lambdas(void)
{
    [] {
        std::cout << "Hello, Lambda" << std::endl;
    }();        /* directly call the lambada function */

    lambda();

    int id = 0;
    auto func = [id]() mutable
    {
        std::cout << "id: " << id << std::endl;
        ++id;
    };

    id = 42;
    func();
    func();
    func();
    std::cout << "id: " << id << std::endl;
}

void lambda_expression1()
{
    int id = 0;
    auto f = [id]() mutable
    {
        std::cout << "lambda_expression_1 id = " << id << std::endl;
        ++id;
    };

    id = 42;
    f();
    f();
    f();
    std::cout << "lambda_expression_1 id becomes:" << id << "\n" << std::endl;
}

void lambda_expression2()
{
    int id = 0;
    auto f = [&id](int param)
    {
        std::cout << "lambda_ex[ression_2 id = " << id << std::endl;
        ++id;
        ++param;
    };

    id = 42;
    f(7);
    f(7);
    f(7);
    std::cout << "lambda_expression_2 id becomes :" << id << "\n" << std::endl;
}

void lambda_expression3()
{
    int id = 0;
    auto f = [id]()
    {
        std::cout << "lambda_expression_3 id = " << id << std::endl;
        // ++id;   /* cannot assign a variable captured by copy in a non-mutable lambda */
    };

    id = 42;
    f();
    f();
    f();
    std::cout << "lambda_expression_3 id becomes : " << id << "\n" << std::endl;
}

void lambda_expression4()
{
    int id = 0;
    auto f = [id]() mutable -> decltype(id)
    {
        std::cout << "lambda_expression_4 id = " << id << std::endl;
        ++id;
        static int x = 5;
        int y = 6;
        return id;
    };

    id = 42;
    f();
    f();
    f();
    std::cout << "lambda_expression_4 id becomes : " << id << "\n" << std::endl;
}
