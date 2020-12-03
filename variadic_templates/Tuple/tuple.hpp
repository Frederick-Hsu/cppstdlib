#ifndef TUPLE_HPP
#define TUPLE_HPP

    #include <iostream>

namespace MySTL
{
    /* Prototypes: */
    template<typename... ArgTypes> class tuple;
    template<> class tuple<>;
    template<typename Head, typename... Tail> class tuple<Head, Tail...>;

/*================================================================================================*/

    /* Definitions: */
    template<> class tuple<>
    {
    };

    template<typename Head, typename... Tail>
    class tuple<Head, Tail...> : private tuple<Tail...>
    {
        // typedef tuple<Tail...> inherited;
        using inherited = tuple<Tail...>;
    public:
        tuple();
        tuple(Head v, Tail... vtail);
        Head head();
        inherited& tail();
    protected:
        Head m_head;
    };

/*================================================================================================*/

    /* Implementations: */
    template<typename Head, typename... Tail> tuple<Head, Tail...>::tuple()
    {
    }

    template<typename Head, typename... Tail> tuple<Head, Tail...>::tuple(Head v, Tail... vtail)
        : m_head(v), inherited(vtail...)
    {
    }

    template<typename Head, typename... Tail> Head tuple<Head, Tail...>::head()
    {
        return m_head;
    }

    template<typename Head, typename... Tail>
    typename tuple<Head, Tail...>::inherited& tuple<Head, Tail...>::tail()
    {
        return *this;
    }
}
    template<typename... ArgTypes>
    std::ostream& operator<<(std::ostream& os, const MySTL::tuple<ArgTypes...>& tpl);

    void test_user_implemented_tuple(void);

#endif  /* TUPLE_HPP*/
