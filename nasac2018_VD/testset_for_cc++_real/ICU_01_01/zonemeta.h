#ifndef ZONEMETA_H
#define ZONEMETA_H

#include "uvector.h"
#include "unistr.h"

typedef struct OlsonToMetaMappingEntry
{
    const char16_t *mzid; // const because it's a reference to a resource bundle string.
    double from;
    double to;
} OlsonToMetaMappingEntry;

class ZoneMeta
{
public:
    static const UVector *U_EXPORT2 getMetazoneMappings(const UnicodeString &tzid);
    
private:
    static UVector *createMetazoneMappings(const UnicodeString &tzid);
};

#endif