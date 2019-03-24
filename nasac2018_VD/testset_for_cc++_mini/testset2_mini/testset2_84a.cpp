
#include "std_testcase.h"
#include "testset2_84.h"

namespace testset2_84
{



void foo_bar()
{
    char * data;
    
    data = NULL;
    testset2_84_foo_bar * foo_barObject = new testset2_84_foo_bar(data);
    delete foo_barObject;
}






static void cwe_foo()
{
    char * data;
    
    data = NULL;
    testset2_84_foo * cwe_fooObject = new testset2_84_foo(data);
    delete cwe_fooObject;
}


static void cwe_bar()
{
    char * data;
    
    data = NULL;
    testset2_84_bar * cwe_barObject = new testset2_84_bar(data);
    delete cwe_barObject;
}

void good()
{
    cwe_foo();
    cwe_bar();
}



} 

