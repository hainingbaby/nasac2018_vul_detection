#ifndef CMEMORY_H
#define CMEMORY_H

#include <string.h>
#include "utypes.h"

/**
 * A function called by <TT>uhash_remove</TT>,
 * <TT>uhash_close</TT>, or <TT>uhash_put</TT> to delete
 * an existing key or value.
 * @param obj A key or value stored in a hashtable
 * @see uprv_deleteUObject
 */
typedef void U_CALLCONV UObjectDeleter(void *obj);

U_CAPI void *U_EXPORT2 uprv_malloc(size_t s);
U_CAPI void U_EXPORT2 uprv_free(void *mem);

#endif