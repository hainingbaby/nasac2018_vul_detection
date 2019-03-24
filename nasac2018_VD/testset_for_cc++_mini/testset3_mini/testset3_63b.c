
#include "std_testcase.h"

#include <wchar.h>



void CWE476_NULL_Pointer_Dereference__char_63b_badSink(char * * dataPtr)
{
    char * data = *dataPtr;
    
    
    printf("%02x\n", data[0]);
}






void CWE476_NULL_Pointer_Dereference__char_63b_cwe_fooSink(char * * dataPtr)
{
    char * data = *dataPtr;
    
    
    printf("%02x\n", data[0]);
}


void CWE476_NULL_Pointer_Dereference__char_63b_cwe_barSink(char * * dataPtr)
{
    char * data = *dataPtr;
    
    if (data != NULL)
    {
        
        printf("%02x\n", data[0]);
    }
    else
    {
        printLine("data is NULL");
    }
}


