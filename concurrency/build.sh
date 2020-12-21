#!/bin/bash
#
# File name     ; build.sh
# Description   : This shell script builds the code files under directory concurrency/
#

g++ -std=c++11 wait_async_tasks.cpp -o wait_async_tasks.o -lpthread

g++ -m32 -std=c++11 thread.cpp -o thread.o -lpthread

g++ -std=c++11 promise_future.cpp -o promise_future.o -lpthread