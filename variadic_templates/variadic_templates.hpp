#ifndef VARIADIC_TEMPLATES_HPP
#define VARIADIC_TEMPLATES_HPP

    /* Includes: */
    #include <iostream>
    #include <vector>

/*================================================================================================*/

    /* Prototypes: */
    template<typename T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec);

/*================================================================================================*/

    /* Definitions: */

/*================================================================================================*/

    /* Implementations: */
    void PrintX()
    {
    }

    /* specific version */
    template<typename T, typename... Types> void PrintX(const T& firstArg, const Types&... args)
    {
        std::cout << firstArg << std::endl;
        PrintX(args...);
    }

    /* generic version */
    template<typename... Types> void PrintX(const Types&... args)
    {
        PrintX(args...);
    }

    template<typename T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
    {
        for (auto& elem : vec)
        {
            os << elem << ",\t";
        }
        return os;
    }

#endif  /* VARIADIC_TEMPLATES_HPP */
