
#include "std_testcase.h"
#include "testset5_81.h"

namespace testset5_81
{



void foo_bar()
{
    int * data;
    data = NULL;
    
    data = (int *)malloc(10);
    const testset5_81_base& baseObject = testset5_81_foo_bar();
    baseObject.action(data);
}






static void cwe_foo()
{
    int * data;
    data = NULL;
    
    data = (int *)malloc(10*sizeof(int));
    const testset5_81_base& baseObject = testset5_81_foo();
    baseObject.action(data);
}

void good()
{
    cwe_foo();
}



} 

