
#include "std_testcase.h"

#include <wchar.h>



void CWE476_NULL_Pointer_Dereference__char_51b_badSink(char * data)
{
    
    
    printf("%02x\n", data[0]);
}






void CWE476_NULL_Pointer_Dereference__char_51b_cwe_fooSink(char * data)
{
    
    
    printf("%02x\n", data[0]);
}


void CWE476_NULL_Pointer_Dereference__char_51b_cwe_barSink(char * data)
{
    
    if (data != NULL)
    {
        
        printf("%02x\n", data[0]);
    }
    else
    {
        printLine("data is NULL");
    }
}


