#ifndef TUP_HPP
#define TUP_HPP

namespace MySTL
{
    /* Definitions: */
    template<typename... ElemTypes> class tup;
    
    template<> class tup<>
    {
    };

    template<typename Head, typename... Tail> class tup<Head, Tail...>
    {
        typedef tup<Tail...> composited;
    protected:
        composited m_tail;
        Head m_head;
    public:
        tup();
        tup(Head v, Tail... vtail);

        Head head();
        composited& tail();
    };

/*================================================================================================*/

    /* Implementations: */

    template<typename Head, typename... Tail> tup<Head, Tail...>::tup()
    {
    }

    template<typename Head, typename... Tail> tup<Head, Tail...>::tup(Head v, Tail... vtail)
        : m_head(v), m_tail(vtail...)
    {
    }

    template<typename Head, typename... Tail> Head tup<Head, Tail...>::head()
    {
        return m_head;
    }

    template<typename Head, typename... Tail>
    typename tup<Head, Tail...>::composited& tup<Head, Tail...>::tail()
    {
        return m_tail;
    }
}

    void test_composited_tup(void);

#endif  /* TUP_HPP */
