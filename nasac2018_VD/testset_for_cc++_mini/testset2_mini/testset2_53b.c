
#include "std_testcase.h"

#include <wchar.h>




void CWE415_Double_Free__malloc_free_char_53c_badSink(char * data);

void CWE415_Double_Free__malloc_free_char_53b_badSink(char * data)
{
    CWE415_Double_Free__malloc_free_char_53c_badSink(data);
}






void CWE415_Double_Free__malloc_free_char_53c_cwe_fooSink(char * data);

void CWE415_Double_Free__malloc_free_char_53b_cwe_fooSink(char * data)
{
    CWE415_Double_Free__malloc_free_char_53c_cwe_fooSink(data);
}


void CWE415_Double_Free__malloc_free_char_53c_cwe_barSink(char * data);

void CWE415_Double_Free__malloc_free_char_53b_cwe_barSink(char * data)
{
    CWE415_Double_Free__malloc_free_char_53c_cwe_barSink(data);
}


