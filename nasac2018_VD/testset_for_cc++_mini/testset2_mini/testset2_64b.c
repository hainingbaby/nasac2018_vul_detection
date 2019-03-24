
#include "std_testcase.h"

#include <wchar.h>



void CWE415_Double_Free__malloc_free_char_64b_badSink(void * dataVoidPtr)
{
    
    char * * dataPtr = (char * *)dataVoidPtr;
    
    char * data = (*dataPtr);
    
    free(data);
}






void CWE415_Double_Free__malloc_free_char_64b_cwe_fooSink(void * dataVoidPtr)
{
    
    char * * dataPtr = (char * *)dataVoidPtr;
    
    char * data = (*dataPtr);
    
    free(data);
}


void CWE415_Double_Free__malloc_free_char_64b_cwe_barSink(void * dataVoidPtr)
{
    
    char * * dataPtr = (char * *)dataVoidPtr;
    
    char * data = (*dataPtr);
    
    
    ; 
}


