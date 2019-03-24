
#include "std_testcase.h"

#include <wchar.h>

extern char * testset3_68b_fooData;
extern char * CWE476_NULL_Pointer_Dereference__char_68_cwe_fooData;
extern char * CWE476_NULL_Pointer_Dereference__char_68_cwe_barData;



void CWE476_NULL_Pointer_Dereference__char_68b_badSink()
{
    char * data = testset3_68b_fooData;
    
    
    printf("%02x\n", data[0]);
}






void CWE476_NULL_Pointer_Dereference__char_68b_cwe_fooSink()
{
    char * data = CWE476_NULL_Pointer_Dereference__char_68_cwe_fooData;
    
    
    printf("%02x\n", data[0]);
}


void CWE476_NULL_Pointer_Dereference__char_68b_cwe_barSink()
{
    char * data = CWE476_NULL_Pointer_Dereference__char_68_cwe_barData;
    
    if (data != NULL)
    {
        
        printf("%02x\n", data[0]);
    }
    else
    {
        printLine("data is NULL");
    }
}


