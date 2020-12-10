/* File name    : wait_async_tasks.cpp
 * Description  : How to check whether the background task has already finished, by polling the future_status::ready 
 * Creator      : Frederique Hsu
 * Creation date: Thur. 10 Dec. 2020
 * Copyright(C) 2020    All rights reserved.
 */

#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>

void doSomething(char letter);

int main(int argc, char* argv[])
{
    std::cout << "Starting 2 operations asynchronously." << std::endl;

    /* start 2 loops in the background printing out the letter '.' or '+' */
    auto f1 = std::async([] { doSomething('.'); });
    auto f2 = std::async([] { doSomething('+'); });

    /* check whether at least one of the background tasks is running */
    if ( (f1.wait_for(std::chrono::seconds(0)) != std::future_status::deferred) ||
         (f2.wait_for(std::chrono::seconds(0)) != std::future_status::deferred) )
    {
        /* poll until at least one of the loops finished */
        while ( (f1.wait_for(std::chrono::seconds(0)) != std::future_status::ready) && 
                (f2.wait_for(std::chrono::seconds(0)) != std::future_status::ready) )
        {
            ;
            std::this_thread::yield();   /* hint to reschedule to the next thread */
        }   
    }
    std::cout << "\n" << std::endl;

    /* Wait for all loops to be finished and process any exception */
    try
    {
        f1.get();
        f2.get();
    }
    catch (const std::exception& e)
    {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
    std::cout << "\nDone!" << std::endl;

    return 0;
}

void doSomething(char letter)
{
    /* random-number generator (using letter as the seed to get different sequences)*/
    std::default_random_engine dre(letter);
    std::uniform_int_distribution<int> id(10, 1000);

    /* loop to print out the letter after a random period of time */
    for (int num = 0; num < 10; num++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
        std::cout.put(letter).flush();
    }
}