#include "temp_objects.hpp"

#include <iostream>
#include <cstring>

void access_temp_objects_lifetime(std::string& s1, std::string& s2, std::string& s3)
{
    const char* cs = (s1 + s2).c_str();     /* s1 + s2 becomes a temporary object, it will be destroyed after this statement */
    std::cout << cs << std::endl;

    if ( (strlen(cs = (s2 + s3).c_str()) < 8) && (cs[0] == 'a') )
    {
        std::cout << cs << std::endl;
    }
}