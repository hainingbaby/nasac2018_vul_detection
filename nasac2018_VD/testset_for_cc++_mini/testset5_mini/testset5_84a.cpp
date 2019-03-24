
#include "std_testcase.h"
#include "testset5_84.h"

namespace testset5_84
{



void foo_bar()
{
    int * data;
    data = NULL;
    testset5_84_foo_bar * foo_barObject = new testset5_84_foo_bar(data);
    delete foo_barObject;
}






static void cwe_foo()
{
    int * data;
    data = NULL;
    testset5_84_foo * cwe_fooObject =  new testset5_84_foo(data);
    delete cwe_fooObject;
}

void good()
{
    cwe_foo();
}



} 

