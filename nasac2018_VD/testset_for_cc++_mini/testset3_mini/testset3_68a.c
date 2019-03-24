
#include "std_testcase.h"

#include <wchar.h>

char * testset3_68a_fooData;
char * CWE476_NULL_Pointer_Dereference__char_68_cwe_fooData;
char * CWE476_NULL_Pointer_Dereference__char_68_cwe_barData;




void CWE476_NULL_Pointer_Dereference__char_68b_badSink();

void testset3_68a_foo()
{
    char * data;
    
    data = NULL;
    testset3_68a_fooData = data;
    CWE476_NULL_Pointer_Dereference__char_68b_badSink();
}






void CWE476_NULL_Pointer_Dereference__char_68b_cwe_fooSink();
void CWE476_NULL_Pointer_Dereference__char_68b_cwe_barSink();


static void cwe_foo()
{
    char * data;
    
    data = "Good";
    CWE476_NULL_Pointer_Dereference__char_68_cwe_fooData = data;
    CWE476_NULL_Pointer_Dereference__char_68b_cwe_fooSink();
}


static void cwe_bar()
{
    char * data;
    
    data = NULL;
    CWE476_NULL_Pointer_Dereference__char_68_cwe_barData = data;
    CWE476_NULL_Pointer_Dereference__char_68b_cwe_barSink();
}

void testset3_68a_bar()
{
    cwe_foo();
    cwe_bar();
}



