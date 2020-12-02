#ifndef COPY_HPP
#define COPY_HPP

    struct NoCopy;
    struct NoDtor;
    class PrivateCopy;

    struct NoCopy
    {
        NoCopy() = default;     /* use the synthesized default constructor */
        NoCopy(const NoCopy&) = delete;     /* erase the copy constructor */
        NoCopy& operator=(const NoCopy&) = delete;  /* erase the assign constructor */
        ~NoCopy() = default;    /* use the synthesized destructor */
    };

    struct NoDtor
    {
        NoDtor() = default;     /* use the synthesized default constructor */
        ~NoDtor() = delete;     /* we cannot destroy object of NoDtor */
    };

    class PrivateCopy
    {
    private:
        /* copy constructor is private, so it is inaccessible to ordinary user code */
        PrivateCopy(const PrivateCopy&);
        /* assign constructor is private, not accessible */
        PrivateCopy& operator=(const PrivateCopy&);
    public:
        /* use the synthesized default constructor */
        PrivateCopy() = default;
        /* users can define the objects of PrivateCopy, but cannot copy them */
        ~PrivateCopy();
    };

    void cannot_destroy_NoDtor_object(void);

#endif  /* COPY_HPP */
