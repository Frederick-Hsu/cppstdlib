#include "Copy.hpp"

void cannot_destroy_NoDtor_object(void)
{
    // NoDtor nd;      /* Error: NoDtor destructor is explicitly marked delete */
    NoDtor *pobj = new NoDtor();    /* OK: but we cannot delete pobj */
    // delete pobj;        /* Error: we cannot delete the obj. ptr., because NoDtor is deleted */
}
