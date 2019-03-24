
#include "std_testcase.h"

#include <wchar.h>



void CWE415_Double_Free__malloc_free_char_63b_badSink(char * * dataPtr)
{
    char * data = *dataPtr;
    
    free(data);
}






void CWE415_Double_Free__malloc_free_char_63b_cwe_fooSink(char * * dataPtr)
{
    char * data = *dataPtr;
    
    free(data);
}


void CWE415_Double_Free__malloc_free_char_63b_cwe_barSink(char * * dataPtr)
{
    char * data = *dataPtr;
    
    
    ; 
}


