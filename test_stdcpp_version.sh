#!/usr/bin/env bash
#

for std in c++98 c++03 gnu++98 gnu++03 c++11 c++0x gnu++11 gnu++0x c++14 c++1y gnu++14 gnu++14 c++17 c++1z gnu++17 gnu++1z c++2a gnu++2a
do
    echo $std
    g++ -std=$std determine_stdcpp_version.cpp -o stdcpp_ver
    ./stdcpp_ver
    echo
done

echo default
g++ determine_stdcpp_version.cpp -o stdcpp_default_ver
./stdcpp_default_ver