#include "auxiliary.h"

#if 0
    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>

    int printf(const char* format, ...)
    {
            va_list arglist;
            int buffing;
            int retval;

            va_start(arglist, format);

            _ASSERTE(format != NULL);

            _lock_str2(1, stdout);

            buffing = _stbuf(stdout);

            retval = _output(stdout,format,arglist);

            _ftbuf(buffing, stdout);

            _unlock_str2(1, stdout);

            return(retval);
    }
#endif
