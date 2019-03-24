
#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE415_Double_Free__malloc_free_char_67_structType
{
    char * structFirst;
} CWE415_Double_Free__malloc_free_char_67_structType;




void CWE415_Double_Free__malloc_free_char_67b_badSink(CWE415_Double_Free__malloc_free_char_67_structType myStruct);

void testset2_67a_foo()
{
    char * data;
    CWE415_Double_Free__malloc_free_char_67_structType myStruct;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    myStruct.structFirst = data;
    CWE415_Double_Free__malloc_free_char_67b_badSink(myStruct);
}






void CWE415_Double_Free__malloc_free_char_67b_cwe_fooSink(CWE415_Double_Free__malloc_free_char_67_structType myStruct);

static void cwe_foo()
{
    char * data;
    CWE415_Double_Free__malloc_free_char_67_structType myStruct;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    myStruct.structFirst = data;
    CWE415_Double_Free__malloc_free_char_67b_cwe_fooSink(myStruct);
}


void CWE415_Double_Free__malloc_free_char_67b_cwe_barSink(CWE415_Double_Free__malloc_free_char_67_structType myStruct);

static void cwe_bar()
{
    char * data;
    CWE415_Double_Free__malloc_free_char_67_structType myStruct;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    myStruct.structFirst = data;
    CWE415_Double_Free__malloc_free_char_67b_cwe_barSink(myStruct);
}

void testset2_67a_bar()
{
    cwe_foo();
    cwe_bar();
}



