
#include "std_testcase.h"

#include <wchar.h>

namespace testset2_62
{




void foo_barSource(char * &data);

void foo_bar()
{
    char * data;
    
    data = NULL;
    foo_barSource(data);
    
    free(data);
}






void cwe_fooSource(char * &data);

static void cwe_foo()
{
    char * data;
    
    data = NULL;
    cwe_fooSource(data);
    
    free(data);
}


void cwe_barSource(char * &data);

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

