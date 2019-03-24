
#include "std_testcase.h"

#include <wchar.h>

namespace testset2_43
{



static void foo_barSource(char * &data)
{
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
}

void foo_bar()
{
    char * data;
    
    data = NULL;
    foo_barSource(data);
    
    free(data);
}






static void cwe_fooSource(char * &data)
{
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
}

static void cwe_foo()
{
    char * data;
    
    data = NULL;
    cwe_fooSource(data);
    
    free(data);
}


static void cwe_barSource(char * &data)
{
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
}

static void cwe_bar()
{
    char * data;
    
    data = NULL;
    cwe_barSource(data);
    
    
    ; 
}

void good()
{
    cwe_foo();
    cwe_bar();
}



} 

