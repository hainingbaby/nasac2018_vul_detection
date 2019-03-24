#include <stdlib.h>

typedef struct OlsonToMetaMappingEntry
{
	const char *mzid;
    double from;
    double to;
} OlsonToMetaMappingEntry;

static void deleteOlsonToMetaMappingEntry(void *obj) {
	OlsonToMetaMappingEntry *entry = (OlsonToMetaMappingEntry*)obj;
    // 
	free(entry);
}

int main()
{
	OlsonToMetaMappingEntry *entry = (OlsonToMetaMappingEntry *)malloc(sizeof(OlsonToMetaMappingEntry));
	if (entry == NULL)
    {
        return -1;
    }
    deleteOlsonToMetaMappingEntry(entry);
    // 
    entry = NULL;
}
