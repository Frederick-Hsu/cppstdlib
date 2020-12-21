/* File name    : determine_stdcpp_version.cpp
 * Description  : Determine what the version number of standard C++ language.
 * Creator      : Frederique Hsu
 * Creation date: Fri.  11 Dec. 2020
 * Copyright(C) 2020    All rights reserved.
 * 
 */

#include <iostream>

int main(int argc, char* argv[])
{
    #if defined (__cplusplus)
        std::cout << "__cplusplus = " << __cplusplus << std::endl;
    #endif

    #if defined (__STRICT_ANSI__)
        std::cout << "__STRICT_ANSI__ = " << __STRICT_ANSI__ << std::endl;
    #endif
    return 0;
}