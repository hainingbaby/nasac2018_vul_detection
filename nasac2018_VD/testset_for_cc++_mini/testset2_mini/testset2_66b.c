
#include "std_testcase.h"

#include <wchar.h>



void CWE415_Double_Free__malloc_free_char_66b_badSink(char * dataArray[])
{
    
    char * data = dataArray[2];
    
    free(data);
}






void CWE415_Double_Free__malloc_free_char_66b_cwe_fooSink(char * dataArray[])
{
    char * data = dataArray[2];
    
    free(data);
}


void CWE415_Double_Free__malloc_free_char_66b_cwe_barSink(char * dataArray[])
{
    char * data = dataArray[2];
    
    
    ; 
}


