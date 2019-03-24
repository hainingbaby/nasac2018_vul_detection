
#include "std_testcase.h"
#include "testset2_82.h"

namespace testset2_82
{



void foo_bar()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    testset2_82_base* baseObject = new testset2_82_foo_bar;
    baseObject->action(data);
    delete baseObject;
}






static void cwe_foo()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    testset2_82_base* baseObject = new testset2_82_foo;
    baseObject->action(data);
    delete baseObject;
}


static void cwe_bar()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    testset2_82_base* baseObject = new testset2_82_bar;
    baseObject->action(data);
    delete baseObject;
}

void good()
{
    cwe_foo();
    cwe_bar();
}



} 

