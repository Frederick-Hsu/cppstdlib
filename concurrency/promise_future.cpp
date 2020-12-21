/* File name    : promise_future.cpp
 * Description  : Demostrate the future objects retrieving the result,
 *              : while promise objects passing the argument.
 *              : How promise and future objects co-work?
 * Creator      : Frederique Hsu
 * Creation date: Sat.  19 Dec. 2020
 * Copyright(C) 2020    All rights reserved.
 *
 */

#include <thread>
#include <future>
#include <iostream>


void doSomething(std::promise<std::string>& p);

int main(int argc, char* argv[])
{
    try
    {
        /* start a thread by using a promise to store the outcome */
        std::promise<std::string> param;
        std::thread backgroundTask(doSomething, std::ref(param));
        backgroundTask.detach();

        /* create tje future to process the outcome */
        std::future<std::string> result(param.get_future());

        /* retrieve the result */
        std::cout << "result: " << result.get() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "EXCEPTION: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "EXCEPTION " << std::endl;
    }

    return 0;
}

void doSomething(std::promise<std::string>& p)
{
    try
    {
        std::cout << "read char ('x' for exception): ";
        char letter = std::cin.get();
        if (letter == 'x')
        {
            throw std::runtime_error(std::string("char ") + letter + " read.");
        }

        std::string str = std::string("char '") + letter + "' processed.";
        p.set_value(std::move(str));                    /* store result */
    }
    catch (...)
    {
        p.set_exception(std::current_exception());      /* store exception */
    }
}
