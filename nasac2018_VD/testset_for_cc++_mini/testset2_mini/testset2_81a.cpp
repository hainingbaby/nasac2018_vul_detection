
#include "std_testcase.h"
#include "testset2_81.h"

namespace testset2_81
{



void foo_bar()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    const testset2_81_base& baseObject = testset2_81_foo_bar();
    baseObject.action(data);
}






static void cwe_foo()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    const testset2_81_base& baseObject = testset2_81_foo();
    baseObject.action(data);
}


static void cwe_bar()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    const testset2_81_base& baseObject = testset2_81_bar();
    baseObject.action(data);
}

void good()
{
    cwe_foo();
    cwe_bar();
}



} 

