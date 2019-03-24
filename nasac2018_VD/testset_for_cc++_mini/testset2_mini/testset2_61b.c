
#include "std_testcase.h"

#include <wchar.h>



char * CWE415_Double_Free__malloc_free_char_61b_badSource(char * data)
{
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    return data;
}






char * CWE415_Double_Free__malloc_free_char_61b_cwe_fooSource(char * data)
{
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    return data;
}


char * CWE415_Double_Free__malloc_free_char_61b_cwe_barSource(char * data)
{
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    return data;
}


