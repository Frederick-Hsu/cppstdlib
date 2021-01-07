#ifndef OBJECT_PLACEMENT_HPP
#define OBJECT_PLACEMENT_HPP

    #include <cstddef>

    class Arena;

    class Arena
    {
    public:
        virtual void* alloc(size_t) = 0;
        virtual void  free(void*)   = 0;
    };

    void* operator new(size_t sz, Arena* a);
    
    // void* operator new(size_t, void* ptr);
    // void  operator delete(void* ptr);

#endif  /* OBJECT_PLACEMENT_HPP */