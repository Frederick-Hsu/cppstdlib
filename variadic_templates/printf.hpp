#ifndef PRINTF_HPP
#define PRINTF_HPP

    /* Includes: */
    #include <iostream>

/*================================================================================================*/

namespace MySTL
{
    /* Prototypes: */
    void printf(const char* format);
    template<typename T, typename... Types> void printf(const char* format,
                                                        T value,
                                                        Types&... args);

/*================================================================================================*/

    /* Implementations: */
    void printf(const char* format)
    {
        while (*format)
        {
            if ((*format == '%') && (*(++format) != '%'))
            {
                throw std::runtime_error("invalid format string: missing arguments.\n");
            }
            std::cout << *(format++);
        }
    }

    template<typename T, typename... Types> void printf(const char* format,
                                                        T value,
                                                        Types&... args)
    {
        while (*format)
        {
            if ((*format == '%') && (*(++format) != '%'))
            {
                std::cout << value;
                printf(++format, args...);
                return;
            }
            std::cout << *(format++);
        }
        throw std::logic_error("extra arguments provided to printf.\n");
    }
}
#endif  /* PRINTF_HPP */
