
#include "std_testcase.h"
#include "testset3_82.h"

namespace testset3_82
{



void foo_bar()
{
    char * data;
    
    data = NULL;
    testset3_82_base* baseObject = new testset3_82_foo_bar;
    baseObject->action(data);
    delete baseObject;
}






static void cwe_foo()
{
    char * data;
    
    data = "Good";
    testset3_82_base* baseObject = new testset3_82_foo;
    baseObject->action(data);
    delete baseObject;
}


static void cwe_bar()
{
    char * data;
    
    data = NULL;
    testset3_82_base* baseObject = new testset3_82_bar;
    baseObject->action(data);
    delete baseObject;
}

void good()
{
    cwe_foo();
    cwe_bar();
}



} 

