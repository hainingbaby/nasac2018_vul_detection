
#include "std_testcase.h"

#include <wchar.h>




void CWE476_NULL_Pointer_Dereference__char_66b_badSink(char * dataArray[]);

void testset3_66a_foo()
{
    char * data;
    char * dataArray[5];
    
    data = NULL;
    
    dataArray[2] = data;
    CWE476_NULL_Pointer_Dereference__char_66b_badSink(dataArray);
}






void CWE476_NULL_Pointer_Dereference__char_66b_cwe_fooSink(char * dataArray[]);

static void cwe_foo()
{
    char * data;
    char * dataArray[5];
    
    data = "Good";
    dataArray[2] = data;
    CWE476_NULL_Pointer_Dereference__char_66b_cwe_fooSink(dataArray);
}


void CWE476_NULL_Pointer_Dereference__char_66b_cwe_barSink(char * dataArray[]);

static void cwe_bar()
{
    char * data;
    char * dataArray[5];
    
    data = NULL;
    dataArray[2] = data;
    CWE476_NULL_Pointer_Dereference__char_66b_cwe_barSink(dataArray);
}

void testset3_66a_bar()
{
    cwe_foo();
    cwe_bar();
}



