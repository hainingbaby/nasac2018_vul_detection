
#include "std_testcase.h"

#include <wchar.h>

char * testset2_68a_fooData;
char * CWE415_Double_Free__malloc_free_char_68_cwe_fooData;
char * CWE415_Double_Free__malloc_free_char_68_cwe_barData;




void CWE415_Double_Free__malloc_free_char_68b_badSink();

void testset2_68a_foo()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    testset2_68a_fooData = data;
    CWE415_Double_Free__malloc_free_char_68b_badSink();
}






void CWE415_Double_Free__malloc_free_char_68b_cwe_fooSink();
void CWE415_Double_Free__malloc_free_char_68b_cwe_barSink();


static void cwe_foo()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    CWE415_Double_Free__malloc_free_char_68_cwe_fooData = data;
    CWE415_Double_Free__malloc_free_char_68b_cwe_fooSink();
}


static void cwe_bar()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    CWE415_Double_Free__malloc_free_char_68_cwe_barData = data;
    CWE415_Double_Free__malloc_free_char_68b_cwe_barSink();
}

void testset2_68a_bar()
{
    cwe_foo();
    cwe_bar();
}



