
#include "std_testcase.h"

#include <wchar.h>




void CWE415_Double_Free__malloc_free_char_66b_badSink(char * dataArray[]);

void testset2_66a_foo()
{
    char * data;
    char * dataArray[5];
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    
    dataArray[2] = data;
    CWE415_Double_Free__malloc_free_char_66b_badSink(dataArray);
}






void CWE415_Double_Free__malloc_free_char_66b_cwe_fooSink(char * dataArray[]);

static void cwe_foo()
{
    char * data;
    char * dataArray[5];
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    dataArray[2] = data;
    CWE415_Double_Free__malloc_free_char_66b_cwe_fooSink(dataArray);
}


void CWE415_Double_Free__malloc_free_char_66b_cwe_barSink(char * dataArray[]);

static void cwe_bar()
{
    char * data;
    char * dataArray[5];
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    dataArray[2] = data;
    CWE415_Double_Free__malloc_free_char_66b_cwe_barSink(dataArray);
}

void testset2_66a_bar()
{
    cwe_foo();
    cwe_bar();
}



