
#include "std_testcase.h"

#include <wchar.h>

static char * testset2_45_fooData;
static char * CWE415_Double_Free__malloc_free_char_45_cwe_fooData;
static char * CWE415_Double_Free__malloc_free_char_45_cwe_barData;



static void badSink()
{
    char * data = testset2_45_fooData;
    
    free(data);
}

void testset2_45_foo()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    testset2_45_fooData = data;
    badSink();
}






static void cwe_fooSink()
{
    char * data = CWE415_Double_Free__malloc_free_char_45_cwe_fooData;
    
    free(data);
}

static void cwe_foo()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    CWE415_Double_Free__malloc_free_char_45_cwe_fooData = data;
    cwe_fooSink();
}


static void cwe_barSink()
{
    char * data = CWE415_Double_Free__malloc_free_char_45_cwe_barData;
    
    
    ; 
}

static void cwe_bar()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    CWE415_Double_Free__malloc_free_char_45_cwe_barData = data;
    cwe_barSink();
}

void testset2_45_bar()
{
    cwe_foo();
    cwe_bar();
}



