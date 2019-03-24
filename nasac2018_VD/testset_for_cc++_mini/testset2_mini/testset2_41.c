
#include "std_testcase.h"

#include <wchar.h>



static void badSink(char * data)
{
    
    free(data);
}

void testset2_41_foo()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    badSink(data);
}






static void cwe_fooSink(char * data)
{
    
    free(data);
}

static void cwe_foo()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    cwe_fooSink(data);
}


static void cwe_barSink(char * data)
{
    
    
    ; 
}

static void cwe_bar()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    cwe_barSink(data);
}

void testset2_41_bar()
{
    cwe_bar();
    cwe_foo();
}



