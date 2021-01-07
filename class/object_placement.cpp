#include "object_placement.hpp"

void* operator new(size_t sz, Arena* a)
{
    return a->alloc(sz);
}

#if defined (USER_PLACEMENT_NEW)
    void* operator new(size_t, void* ptr)   /* 显式放置运算符 */
    {
        return ptr;
    }

    void* buf = reinterpret_cast<void*>(0xF00F);	/* 重要地址 */
    X* p2 = new (buf)X;		/* 在'buf'处构造X时调用: operator new(sizeof(X), buf) */
#endif