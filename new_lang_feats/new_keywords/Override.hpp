#ifndef OVERRIDE_HPP
#define OVERRIDE_HPP

    class Base;
    class Derived;
    class FinalBase;

    class Base
    {
    public:
        virtual void vfunc(float);
        virtual void f(void) final;     /* final keyword here to prevent from overriding in derived class */
    };

    class Derived : public Base
    {
    public:
        virtual void vfunc(float) override;
    };

    /* final keyword is used to prevent from inheritance by other class */
    class FinalBase final
    {
    };

#endif  /* OVERRIDE_HPP */
