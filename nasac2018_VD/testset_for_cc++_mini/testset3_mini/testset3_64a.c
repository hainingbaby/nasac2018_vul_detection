
#include "std_testcase.h"

#include <wchar.h>




void CWE476_NULL_Pointer_Dereference__char_64b_badSink(void * dataVoidPtr);

void testset3_64a_foo()
{
    char * data;
    
    data = NULL;
    CWE476_NULL_Pointer_Dereference__char_64b_badSink(&data);
}






void CWE476_NULL_Pointer_Dereference__char_64b_cwe_fooSink(void * dataVoidPtr);

static void cwe_foo()
{
    char * data;
    
    data = "Good";
    CWE476_NULL_Pointer_Dereference__char_64b_cwe_fooSink(&data);
}


void CWE476_NULL_Pointer_Dereference__char_64b_cwe_barSink(void * dataVoidPtr);

static void cwe_bar()
{
    char * data;
    
    data = NULL;
    CWE476_NULL_Pointer_Dereference__char_64b_cwe_barSink(&data);
}

void testset3_64a_bar()
{
    cwe_foo();
    cwe_bar();
}



