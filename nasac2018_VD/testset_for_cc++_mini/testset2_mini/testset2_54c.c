
#include "std_testcase.h"

#include <wchar.h>




void CWE415_Double_Free__malloc_free_char_54d_badSink(char * data);

void CWE415_Double_Free__malloc_free_char_54c_badSink(char * data)
{
    CWE415_Double_Free__malloc_free_char_54d_badSink(data);
}






void CWE415_Double_Free__malloc_free_char_54d_cwe_fooSink(char * data);

void CWE415_Double_Free__malloc_free_char_54c_cwe_fooSink(char * data)
{
    CWE415_Double_Free__malloc_free_char_54d_cwe_fooSink(data);
}


void CWE415_Double_Free__malloc_free_char_54d_cwe_barSink(char * data);

void CWE415_Double_Free__malloc_free_char_54c_cwe_barSink(char * data)
{
    CWE415_Double_Free__malloc_free_char_54d_cwe_barSink(data);
}


