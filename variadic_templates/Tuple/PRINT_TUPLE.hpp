#ifndef PRINT_TUPLE_HPP
#define PRINT_TUPLE_HPP

    /* Includes: */
    #include <iostream>
    #include <tuple>

/*================================================================================================*/

    /* Prototypes: */
    template<int IDX, int MAX, typename... ArgTypes> struct PRINT_TUPLE;
    template<int MAX, typename... ArgTypes> struct PRINT_TUPLE<MAX, MAX, ArgTypes...>;
    template<typename... ArgTypes> std::ostream& operator<<(std::ostream& os, const std::tuple<ArgTypes...>& tpl);

/*================================================================================================*/

    /* Definitions: */
    template<int IDX, int MAX, typename... ArgTypes>
    struct PRINT_TUPLE      /* print elements with index IDX of tuple with MAX elements */
    {
        static void print(std::ostream& os, const std::tuple<ArgTypes...>& tpl);
    };

    template<int MAX, typename... ArgTypes>
    struct PRINT_TUPLE<MAX, MAX, ArgTypes...>       /* partial specialization to end the recursion */
    {
        static void print(std::ostream& os, const std::tuple<ArgTypes...>& tpl);
    };

/*================================================================================================*/

    /* Implementations: */
    template<typename... ArgTypes> std::ostream& operator<<(std::ostream& os,
                                                            const std::tuple<ArgTypes...>& tpl)
    {
        os << "(";
        PRINT_TUPLE<0, sizeof...(ArgTypes), ArgTypes...>::print(os, tpl);
        return os << ")";
    }

    template<int IDX, int MAX, typename... ArgTypes>
    void PRINT_TUPLE<IDX, MAX, ArgTypes...>::print(std::ostream& os,
                                                   const std::tuple<ArgTypes...>& tpl)
    {
        os << std::get<IDX>(tpl) << ((IDX+1 == MAX) ? "" : ", ");
        PRINT_TUPLE<IDX+1, MAX, ArgTypes...>::print(os, tpl);
    }

    template<int MAX, typename... ArgTypes>
    void PRINT_TUPLE<MAX, MAX, ArgTypes...>::print(std::ostream&, const std::tuple<ArgTypes...>&)
    {
    }

#endif  /* PRINT_TUPLE_HPP */
