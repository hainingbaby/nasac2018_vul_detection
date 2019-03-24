
#include "std_testcase.h"

#include <wchar.h>




void CWE415_Double_Free__malloc_free_char_65b_badSink(char * data);

void testset2_65a_foo()
{
    char * data;
    
    void (*funcPtr) (char *) = CWE415_Double_Free__malloc_free_char_65b_badSink;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    
    funcPtr(data);
}






void CWE415_Double_Free__malloc_free_char_65b_cwe_fooSink(char * data);

static void cwe_foo()
{
    char * data;
    void (*funcPtr) (char *) = CWE415_Double_Free__malloc_free_char_65b_cwe_fooSink;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    funcPtr(data);
}


void CWE415_Double_Free__malloc_free_char_65b_cwe_barSink(char * data);

static void cwe_bar()
{
    char * data;
    void (*funcPtr) (char *) = CWE415_Double_Free__malloc_free_char_65b_cwe_barSink;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    funcPtr(data);
}

void testset2_65a_bar()
{
    cwe_foo();
    cwe_bar();
}



