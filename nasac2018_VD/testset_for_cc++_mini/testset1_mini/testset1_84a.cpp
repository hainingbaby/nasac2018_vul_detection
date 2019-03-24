
#include "std_testcase.h"
#include "testset1_84.h"

namespace testset1_84
{



void foo_bar()
{
    int data;
    
    data = -1;
    testset1_84_foo_bar * foo_barObject = new testset1_84_foo_bar(data);
    delete foo_barObject;
}






static void cwe_foo()
{
    int data;
    
    data = -1;
    testset1_84_foo * cwe_fooObject = new testset1_84_foo(data);
    delete cwe_fooObject;
}


static void cwe_bar()
{
    int data;
    
    data = -1;
    testset1_84_bar * cwe_barObject = new testset1_84_bar(data);
    delete cwe_barObject;
}

void good()
{
    cwe_foo();
    cwe_bar();
}



} 

