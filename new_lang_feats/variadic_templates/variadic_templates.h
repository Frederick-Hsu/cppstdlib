#ifndef VARIADIC_TEMPLATES_H
#define VARIADIC_TEMPLATES_H

    #include <iostream>

    /* Prototypes : */
    void PrintX();
    template<typename T, typename... Types> void PrintX(const T& firstArg, const Types&... args);

    /*============================================================================================*/

    /* Implementations : */
    void PrintX()
    {
    }

    template<typename T, typename... Types> void PrintX(const T& firstArg, const Types&... args)
    {
        std::cout << firstArg << std::endl;     /* print first argument */
#if defined (DEBUG)
        std::cout << "sizeof...(args) = " << sizeof...(args) << std::endl;
#endif
        PrintX(args...);        /* call PrintX() for remaining arguments */
    }

#endif  /* VARIADIC_TEMPLATES_H */
