#ifndef UVECTOR_H
#define UVECTOR_H

#include "uelement.h"
#include "cmemory.h"
#include "utypes.h"


class UVector
{
    // NOTE: UVector uses the UHashKey (union of void* and int32_t) as
    // its basic storage type.  It uses UElementsAreEqual as its
    // comparison function.  It uses UObjectDeleter as its deleter
    // function.  These are named for hashtables, but used here as-is
    // rather than duplicating the type.  This allows sharing of
    // support functions.

private:
    int count;

    int capacity;

    UElement *elements;

    UObjectDeleter *deleter;

    UElementsAreEqual *comparer;

public:
    UVector(UErrorCode &status);

    UVector(int initialCapacity, UErrorCode &status);

    UVector(UObjectDeleter *d, UElementsAreEqual *c, UErrorCode &status);

    UVector(UObjectDeleter *d, UElementsAreEqual *c, int initialCapacity, UErrorCode &status);

    virtual ~UVector();

    void removeAllElements();

private:
    void _init(int initialCapacity, UErrorCode &status);

};

#endif