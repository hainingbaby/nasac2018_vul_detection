
#include "std_testcase.h"
#include "testset2_83.h"

namespace testset2_83
{



void foo_bar()
{
    char * data;
    
    data = NULL;
    testset2_83_foo_bar foo_barObject(data);
}






static void cwe_foo()
{
    char * data;
    
    data = NULL;
    testset2_83_foo cwe_fooObject(data);
}


static void cwe_bar()
{
    char * data;
    
    data = NULL;
    testset2_83_bar cwe_barObject(data);
}

void good()
{
    cwe_foo();
    cwe_bar();
}



} 

