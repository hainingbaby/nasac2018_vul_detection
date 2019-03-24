
#include "std_testcase.h"
#include "testset1_83.h"

namespace testset1_83
{



void foo_bar()
{
    int data;
    
    data = -1;
    testset1_83_foo_bar foo_barObject(data);
}






static void cwe_foo()
{
    int data;
    
    data = -1;
    testset1_83_foo cwe_fooObject(data);
}


static void cwe_bar()
{
    int data;
    
    data = -1;
    testset1_83_bar cwe_barObject(data);
}

void good()
{
    cwe_foo();
    cwe_bar();
}



} 

