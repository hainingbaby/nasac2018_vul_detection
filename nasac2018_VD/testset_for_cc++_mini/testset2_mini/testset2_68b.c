
#include "std_testcase.h"

#include <wchar.h>

extern char * testset2_68b_fooData;
extern char * CWE415_Double_Free__malloc_free_char_68_cwe_fooData;
extern char * CWE415_Double_Free__malloc_free_char_68_cwe_barData;



void CWE415_Double_Free__malloc_free_char_68b_badSink()
{
    char * data = testset2_68b_fooData;
    
    free(data);
}






void CWE415_Double_Free__malloc_free_char_68b_cwe_fooSink()
{
    char * data = CWE415_Double_Free__malloc_free_char_68_cwe_fooData;
    
    free(data);
}


void CWE415_Double_Free__malloc_free_char_68b_cwe_barSink()
{
    char * data = CWE415_Double_Free__malloc_free_char_68_cwe_barData;
    
    
    ; 
}


