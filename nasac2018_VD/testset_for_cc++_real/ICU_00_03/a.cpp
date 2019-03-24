#include <stdlib.h>

typedef struct OlsonToMetaMappingEntry
{
	const char *mzid;
    double from;
    double to;
} OlsonToMetaMappingEntry;

static int freed = 0;

static void deleteOlsonToMetaMappingEntry(void *obj) {
	OlsonToMetaMappingEntry *entry = (OlsonToMetaMappingEntry*)obj;
    // 
	free(entry);
	entry=NULL;
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
    if (freed != NULL)
    	// 
        free(entry); //double free occurs
}
