#include "object_placement.hpp"

extern Arena* Persistent;
extern Arena* Shared;

#if 0
    template<typename T> void create(size_t size)
    {
        T* p = new (Persistent)T(size);		/* 在某持续性(Persistent)存储分配T*/
        T* q = new (Shared)T(size);			/* 在共享的(Shared)存储分配T */
    }

    template<typename T> void destroy(T* ptr, Arena* a)
    {
        ptr->~T();      /* 显式调用析构函数 */
        a->free(ptr);	/* 释放存储 */
    }
#endif