#include "putilimp.h"
#include "cmemory.h"
#include <stdlib.h>

/* uprv_malloc(0) returns a pointer to this read-only data. */
static const int zeroMem[] = {0, 0, 0, 0, 0, 0};

U_CAPI void *U_EXPORT2
uprv_malloc(size_t s)
{
    if (s > 0)
    {
        return uprv_default_malloc(s);
    }
    else
    {
        return (void *)zeroMem;
    }
}

U_CAPI void U_EXPORT2
uprv_free(void *buffer)
{
    if (buffer != zeroMem)
    {
        uprv_default_free(buffer);
    }
}