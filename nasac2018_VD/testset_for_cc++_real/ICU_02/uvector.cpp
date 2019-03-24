#include "uvector.h"
#include "cmemory.h"
#include "uelement.h"
#include "utypes.h"

#define DEFAULT_CAPACITY 8

UVector::UVector(UErrorCode &status) :
    count(0),
    capacity(0),
    elements(0),
    deleter(0),
    comparer(0)
{
    _init(DEFAULT_CAPACITY, status);
}

UVector::UVector(int initialCapacity, UErrorCode &status) :
    count(0),
    capacity(0),
    elements(0),
    deleter(0),
    comparer(0)
{
    _init(initialCapacity, status);
}

UVector::UVector(UObjectDeleter *d, UElementsAreEqual *c, UErrorCode &status) :
    count(0),
    capacity(0),
    elements(0),
    deleter(d),
    comparer(c)
{
    _init(DEFAULT_CAPACITY, status);
}

UVector::UVector(UObjectDeleter *d, UElementsAreEqual *c, int initialCapacity, UErrorCode &status) :
    count(0),
    capacity(0),
    elements(0),
    deleter(d),
    comparer(c)
{
    _init(initialCapacity, status);
}

void UVector::_init(int initialCapacity, UErrorCode &status)
{
    if (U_FAILURE(status))
    {
        return;
    }
    // Fix bogus initialCapacity values; avoid malloc(0) and integer overflow
    if ((initialCapacity < 1) || (initialCapacity > (int)(INT32_MAX / sizeof(UElement))))
    {
        initialCapacity = DEFAULT_CAPACITY;
    }
    elements = (UElement *)uprv_malloc(sizeof(UElement) * initialCapacity);
    if (elements == 0)
    {
        status = U_MEMORY_ALLOCATION_ERROR;
    }
    else
    {
        capacity = initialCapacity;
    }
}

void UVector::removeAllElements(void)
{
    if (deleter != 0)
    {
        for (int i = 0; i < count; ++i)
        {
            if (elements[i].pointer != 0)
            {
                (*deleter)(elements[i].pointer);
            }
        }
    }
    count = 0;
}

UVector::~UVector()
{
    removeAllElements();
    uprv_free(elements);
    elements = 0;
}