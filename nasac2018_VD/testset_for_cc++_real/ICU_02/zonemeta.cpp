#include "zonemeta.h"
#include "platform.h"
#include "utypes.h"

class UVector;

/**
 * Deleter for OlsonToMetaMappingEntry
 */
 #define uprv_default_free(x) free(x)
 static const int zeroMem[] = {0, 0, 0, 0, 0, 0};
/*uprv_free(void *buffer)
{
    if (buffer != zeroMem)
    {
        uprv_default_free(buffer);
    }
}*/
static void U_CALLCONV
deleteOlsonToMetaMappingEntry(void *obj)
{
    OlsonToMetaMappingEntry *entry = (OlsonToMetaMappingEntry *)obj;
    uprv_free(entry);
}

const UVector *U_EXPORT2
ZoneMeta::getMetazoneMappings(const UnicodeString &tzid)
{
    // miss the cache - create new one
    UVector *tmpResult = createMetazoneMappings(tzid);
    return tmpResult;
}

UVector *ZoneMeta::createMetazoneMappings(const UnicodeString &tzid)
{
    UVector *mzMappings = NULL;
    UErrorCode status = U_ZERO_ERROR;
    OlsonToMetaMappingEntry *entry = (OlsonToMetaMappingEntry *)uprv_malloc(sizeof(OlsonToMetaMappingEntry));
    if (entry == NULL)
    {
        status = U_MEMORY_ALLOCATION_ERROR;
    }
    entry->mzid = NULL;
    entry->from = 0;
    entry->to = 0;
    mzMappings = new UVector(deleteOlsonToMetaMappingEntry, NULL, status);
    if (U_FAILURE(status))
    {
        delete mzMappings;
        ////inlining function
        ////deleteOlsonToMetaMappingEntry(entry);
        OlsonToMetaMappingEntry *entry2 = (OlsonToMetaMappingEntry *)entry;
   		uprv_free(entry2);
        uprv_free(entry); //double free occurs
    }
}