
#include "std_testcase.h"

#include <wchar.h>




void CWE476_NULL_Pointer_Dereference__char_65b_badSink(char * data);

void testset3_65a_foo()
{
    char * data;
    
    void (*funcPtr) (char *) = CWE476_NULL_Pointer_Dereference__char_65b_badSink;
    
    data = NULL;
    
    funcPtr(data);
}






void CWE476_NULL_Pointer_Dereference__char_65b_cwe_fooSink(char * data);

static void cwe_foo()
{
    char * data;
    void (*funcPtr) (char *) = CWE476_NULL_Pointer_Dereference__char_65b_cwe_fooSink;
    
    data = "Good";
    funcPtr(data);
}


void CWE476_NULL_Pointer_Dereference__char_65b_cwe_barSink(char * data);

static void cwe_bar()
{
    char * data;
    void (*funcPtr) (char *) = CWE476_NULL_Pointer_Dereference__char_65b_cwe_barSink;
    
    data = NULL;
    funcPtr(data);
}

void testset3_65a_bar()
{
    cwe_foo();
    cwe_bar();
}



