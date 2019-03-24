
#include "std_testcase.h"

#include <wchar.h>




int testset2_22a_fooGlobal = 0;

void testset2_22a_fooSink(char * data);

void testset2_22a_foo()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    testset2_22a_fooGlobal = 1; 
    testset2_22a_fooSink(data);
}






int CWE415_Double_Free__malloc_free_char_22_cwe_bar1Global = 0;
int CWE415_Double_Free__malloc_free_char_22_cwe_bar2Global = 0;
int CWE415_Double_Free__malloc_free_char_22_cwe_fooGlobal = 0;


void CWE415_Double_Free__malloc_free_char_22_cwe_bar1Sink(char * data);

static void cwe_bar1()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    CWE415_Double_Free__malloc_free_char_22_cwe_bar1Global = 0; 
    CWE415_Double_Free__malloc_free_char_22_cwe_bar1Sink(data);
}


void CWE415_Double_Free__malloc_free_char_22_cwe_bar2Sink(char * data);

static void cwe_bar2()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    CWE415_Double_Free__malloc_free_char_22_cwe_bar2Global = 1; 
    CWE415_Double_Free__malloc_free_char_22_cwe_bar2Sink(data);
}


void CWE415_Double_Free__malloc_free_char_22_cwe_fooSink(char * data);

static void cwe_foo()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    CWE415_Double_Free__malloc_free_char_22_cwe_fooGlobal = 1; 
    CWE415_Double_Free__malloc_free_char_22_cwe_fooSink(data);
}

void testset2_22a_bar()
{
    cwe_bar1();
    cwe_bar2();
    cwe_foo();
}



