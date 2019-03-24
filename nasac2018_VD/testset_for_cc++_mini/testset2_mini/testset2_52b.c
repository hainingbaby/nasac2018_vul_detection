
#include "std_testcase.h"

#include <wchar.h>




void CWE415_Double_Free__malloc_free_char_52c_badSink(char * data);

void CWE415_Double_Free__malloc_free_char_52b_badSink(char * data)
{
    CWE415_Double_Free__malloc_free_char_52c_badSink(data);
}






void CWE415_Double_Free__malloc_free_char_52c_cwe_fooSink(char * data);

void CWE415_Double_Free__malloc_free_char_52b_cwe_fooSink(char * data)
{
    CWE415_Double_Free__malloc_free_char_52c_cwe_fooSink(data);
}


void CWE415_Double_Free__malloc_free_char_52c_cwe_barSink(char * data);

void CWE415_Double_Free__malloc_free_char_52b_cwe_barSink(char * data)
{
    CWE415_Double_Free__malloc_free_char_52c_cwe_barSink(data);
}


