#ifndef NONCOPYABLE_HPP
#define NONCOPYABLE_HPP

namespace MyBoost
{
    class noncopyable;

    class noncopyable
    {
    protected:
        noncopyable() {}
        ~noncopyable() {}
    private:
        noncopyable(const noncopyable&);
        const noncopyable& operator=(const noncopyable&);
    };
}

    class MyNoncopyableFoo : public MyBoost::noncopyable
    {
    };

#endif  /* NONCOPYABLE_HPP */
