
#include "std_testcase.h"

#include <wchar.h>




void CWE476_NULL_Pointer_Dereference__char_51b_badSink(char * data);

void testset3_51a_foo()
{
    char * data;
    
    data = NULL;
    CWE476_NULL_Pointer_Dereference__char_51b_badSink(data);
}






void CWE476_NULL_Pointer_Dereference__char_51b_cwe_fooSink(char * data);

static void cwe_foo()
{
    char * data;
    
    data = "Good";
    CWE476_NULL_Pointer_Dereference__char_51b_cwe_fooSink(data);
}


void CWE476_NULL_Pointer_Dereference__char_51b_cwe_barSink(char * data);

static void cwe_bar()
{
    char * data;
    
    data = NULL;
    CWE476_NULL_Pointer_Dereference__char_51b_cwe_barSink(data);
}

void testset3_51a_bar()
{
    cwe_foo();
    cwe_bar();
}



