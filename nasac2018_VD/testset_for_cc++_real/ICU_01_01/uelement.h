#ifndef __UELEMENT_H__
#define __UELEMENT_H__

#include "platform.h"

/**
 * A UVector element, or a key or value within a UHashtable.
 * It may be either a 32-bit integral value or an opaque void* pointer.
 * The void* pointer may be smaller than 32 bits (e.g. 24 bits)
 * or may be larger (e.g. 64 bits).
 *
 * Because a UElement is the size of a native pointer or a 32-bit
 * integer, we pass it around by value.
 */
union UElement
{
    void   *pointer;
    int integer;
};
typedef union UElement UElement;

typedef signed char U_CALLCONV UElementsAreEqual(const UElement e1, const UElement e2);

#endif