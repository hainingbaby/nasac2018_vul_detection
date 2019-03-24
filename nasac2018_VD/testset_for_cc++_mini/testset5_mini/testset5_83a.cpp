
#include "std_testcase.h"
#include "testset5_83.h"

namespace testset5_83
{



void foo_bar()
{
    int * data;
    data = NULL;
    testset5_83_foo_bar foo_barObject(data);
}






static void cwe_foo()
{
    int * data;
    data = NULL;
    testset5_83_foo cwe_fooObject(data);
}

void good()
{
    cwe_foo();
}



} 

