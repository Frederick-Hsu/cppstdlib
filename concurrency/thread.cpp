/* File name    : thread.cpp
 * Description  : Study how to create and run the multi-threading.
 *
 */


#include <thread>
#include <chrono>
#include <random>
#include <exception>
#include <iostream>

void doSomething(int num, char letter);

int main(int argc, char* argv[])
{
    std::cout << "Current C++ standard no. = " << __cplusplus << std::endl;
    std::cout << "Current program is " << sizeof(void*) * 8 << "-bit." << std::endl;

    std::cout << "ID of \"no thread\" is: " << std::thread::id() << std::endl;
    try
    {
        std::thread foregroundThread(doSomething, 5, '.');
        std::cout << "- Started foreground thread " << foregroundThread.get_id() << std::endl;

        /* Print out other characters in other background threads */
        for (int i = 0; i < 15; ++i)
        {
            /* Print out 10 characters in separate threads */
            std::thread backgroundThread_no(doSomething, 10, 'a'+i);
            std::cout << "- detach the background thread, id = "
                      << backgroundThread_no.get_id() << std::endl;
            backgroundThread_no.detach();     /* detach thread into the background */
        }

        std::cin.get();     /* wait for any input, just for pause mannually */
        std::cout << "- join the foreground thread, id = " << foregroundThread.get_id() << std::endl;
        foregroundThread.join();    /* Wait for the foreground thread to finish */
    }
    catch (const std::exception& e)
    {
        std::cerr << "EXCEPTION: " << e.what() << std::endl;
    }

    std::cout << "- the main thread ID = " << std::this_thread::get_id() << std::endl;
    return 0;
}

void doSomething(int num, char letter)
{
    try
    {
        /* random-number generator (use letter as seed to get different sequences) */
        std::default_random_engine dre(42 * letter);
        std::uniform_int_distribution<int> id(10, 1000);
        for (int i = 0; i < num; ++i)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
            std::cout.put(letter).flush();
        }
        std::cout << "\n" << std::endl;
    }
    catch (const std::exception& e)
    {
        /* make sure no exception leaves the thread and terminates the program */
        std::cerr << "THREAD-EXCEPTION (thread " << std::this_thread::get_id()
                  << "): " << e.what() << std::endl;

    }
    catch (...)
    {
        std::cerr << "THREAD-EXCEPTION (thread " << std::this_thread::get_id()
                  << "): " << std::endl;
    }
}
