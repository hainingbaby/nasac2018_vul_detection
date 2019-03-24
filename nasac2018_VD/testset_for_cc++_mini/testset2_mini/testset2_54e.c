
#include "std_testcase.h"

#include <wchar.h>



void CWE415_Double_Free__malloc_free_char_54e_badSink(char * data)
{
    
    free(data);
}






void CWE415_Double_Free__malloc_free_char_54e_cwe_fooSink(char * data)
{
    
    free(data);
}


void CWE415_Double_Free__malloc_free_char_54e_cwe_barSink(char * data)
{
    
    
    ; 
}


