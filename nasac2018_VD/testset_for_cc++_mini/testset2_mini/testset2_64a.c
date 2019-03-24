
#include "std_testcase.h"

#include <wchar.h>




void CWE415_Double_Free__malloc_free_char_64b_badSink(void * dataVoidPtr);

void testset2_64a_foo()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    CWE415_Double_Free__malloc_free_char_64b_badSink(&data);
}






void CWE415_Double_Free__malloc_free_char_64b_cwe_fooSink(void * dataVoidPtr);

static void cwe_foo()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    CWE415_Double_Free__malloc_free_char_64b_cwe_fooSink(&data);
}


void CWE415_Double_Free__malloc_free_char_64b_cwe_barSink(void * dataVoidPtr);

static void cwe_bar()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    CWE415_Double_Free__malloc_free_char_64b_cwe_barSink(&data);
}

void testset2_64a_bar()
{
    cwe_foo();
    cwe_bar();
}



