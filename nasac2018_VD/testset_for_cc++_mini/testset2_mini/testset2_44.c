
#include "std_testcase.h"

#include <wchar.h>



static void badSink(char * data)
{
    
    free(data);
}

void testset2_44_foo()
{
    char * data;
    
    void (*funcPtr) (char *) = badSink;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    
    funcPtr(data);
}






static void cwe_fooSink(char * data)
{
    
    free(data);
}

static void cwe_foo()
{
    char * data;
    void (*funcPtr) (char *) = cwe_fooSink;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    funcPtr(data);
}


static void cwe_barSink(char * data)
{
    
    
    ; 
}

static void cwe_bar()
{
    char * data;
    void (*funcPtr) (char *) = cwe_barSink;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    funcPtr(data);
}

void testset2_44_bar()
{
    cwe_foo();
    cwe_bar();
}



