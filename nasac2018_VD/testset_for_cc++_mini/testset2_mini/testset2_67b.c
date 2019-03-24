
#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE415_Double_Free__malloc_free_char_67_structType
{
    char * structFirst;
} CWE415_Double_Free__malloc_free_char_67_structType;



void CWE415_Double_Free__malloc_free_char_67b_badSink(CWE415_Double_Free__malloc_free_char_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    
    free(data);
}






void CWE415_Double_Free__malloc_free_char_67b_cwe_fooSink(CWE415_Double_Free__malloc_free_char_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    
    free(data);
}


void CWE415_Double_Free__malloc_free_char_67b_cwe_barSink(CWE415_Double_Free__malloc_free_char_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    
    
    ; 
}


