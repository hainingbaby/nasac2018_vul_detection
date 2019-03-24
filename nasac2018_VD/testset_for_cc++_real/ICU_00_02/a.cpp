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
	/* do nothing */
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
    free(entry);
}
