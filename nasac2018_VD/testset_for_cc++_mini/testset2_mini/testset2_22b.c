
#include "std_testcase.h"

#include <wchar.h>




extern int testset2_22b_fooGlobal;

void testset2_22b_fooSink(char * data)
{
    if(testset2_22b_fooGlobal)
    {
        
        free(data);
    }
}






extern int CWE415_Double_Free__malloc_free_char_22_cwe_bar1Global;
extern int CWE415_Double_Free__malloc_free_char_22_cwe_bar2Global;
extern int CWE415_Double_Free__malloc_free_char_22_cwe_fooGlobal;


void CWE415_Double_Free__malloc_free_char_22_cwe_bar1Sink(char * data)
{
    if(CWE415_Double_Free__malloc_free_char_22_cwe_bar1Global)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        
        ; 
    }
}


void CWE415_Double_Free__malloc_free_char_22_cwe_bar2Sink(char * data)
{
    if(CWE415_Double_Free__malloc_free_char_22_cwe_bar2Global)
    {
        
        
        ; 
    }
}


void CWE415_Double_Free__malloc_free_char_22_cwe_fooSink(char * data)
{
    if(CWE415_Double_Free__malloc_free_char_22_cwe_fooGlobal)
    {
        
        free(data);
    }
}


