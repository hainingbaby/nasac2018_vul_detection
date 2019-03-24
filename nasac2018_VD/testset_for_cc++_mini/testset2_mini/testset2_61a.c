
#include "std_testcase.h"

#include <wchar.h>




char * CWE415_Double_Free__malloc_free_char_61b_badSource(char * data);

void testset2_61a_foo()
{
    char * data;
    
    data = NULL;
    data = CWE415_Double_Free__malloc_free_char_61b_badSource(data);
    
    free(data);
}






char * CWE415_Double_Free__malloc_free_char_61b_cwe_fooSource(char * data);

static void cwe_foo()
{
    char * data;
    
    data = NULL;
    data = CWE415_Double_Free__malloc_free_char_61b_cwe_fooSource(data);
    
    free(data);
}


char * CWE415_Double_Free__malloc_free_char_61b_cwe_barSource(char * data);

static void cwe_bar()
{
    char * data;
    
    data = NULL;
    data = CWE415_Double_Free__malloc_free_char_61b_cwe_barSource(data);
    
    
    ; 
}

void testset2_61a_bar()
{
    cwe_foo();
    cwe_bar();
}



