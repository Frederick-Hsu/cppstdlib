#ifndef TUPLE_H
#define TUPLE_H

namespace MySTL
{
    /* Forward declarations */
    template<typename... Values> class tuple;

    /*============================================================================================*/

    /* Definitions */
    template<> class tuple<>
    {
    };

    template<typename Head, typename... Tail> class tuple<Head, Tail...> : private tuple<Tail...>
    {
        typedef tuple<Tail...> inherited;
    public:
        tuple();
        tuple(Head v, Tail... vtail);
        Head head();
        inherited& tail();
    protected:
        Head m_head;
    };

    /*============================================================================================*/

    /* Implementations */
    template<typename Head, typename... Tail> tuple<Head, Tail...>::tuple()
    {
    }

    template<typename Head, typename... Tail> tuple<Head, Tail...>::tuple(Head v, Tail... vtail)
        : m_head(v), inherited(vtail...)
    {
    }

    template<typename Head, typename... Tail>
    Head tuple<Head, Tail...>::head()
    {
        return m_head;
    }

    template<typename Head, typename... Tail>
    typename tuple<Head, Tail...>::inherited& tuple<Head, Tail...>::tail()
    {
        return *this;
    }
}

#endif  /* TUPLE_H */
