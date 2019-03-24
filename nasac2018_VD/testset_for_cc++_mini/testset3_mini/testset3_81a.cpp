
#include "std_testcase.h"
#include "testset3_81.h"

namespace testset3_81
{



void foo_bar()
{
    char * data;
    
    data = NULL;
    const testset3_81_base& baseObject = testset3_81_foo_bar();
    baseObject.action(data);
}






static void cwe_foo()
{
    char * data;
    
    data = "Good";
    const testset3_81_base& baseObject = testset3_81_foo();
    baseObject.action(data);
}


static void cwe_bar()
{
    char * data;
    
    data = NULL;
    const testset3_81_base& baseObject = testset3_81_bar();
    baseObject.action(data);
}

void good()
{
    cwe_foo();
    cwe_bar();
}



} 

