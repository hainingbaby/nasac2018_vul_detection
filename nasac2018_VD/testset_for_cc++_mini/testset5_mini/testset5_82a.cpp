
#include "std_testcase.h"
#include "testset5_82.h"

namespace testset5_82
{



void foo_bar()
{
    int * data;
    data = NULL;
    
    data = (int *)malloc(10);
    testset5_82_base* baseObject = new testset5_82_foo_bar;
    baseObject->action(data);
    delete baseObject;
}






static void cwe_foo()
{
    int * data;
    data = NULL;
    
    data = (int *)malloc(10*sizeof(int));
    testset5_82_base* baseObject = new testset5_82_foo;
    baseObject->action(data);
    delete baseObject;
}

void good()
{
    cwe_foo();
}



} 

