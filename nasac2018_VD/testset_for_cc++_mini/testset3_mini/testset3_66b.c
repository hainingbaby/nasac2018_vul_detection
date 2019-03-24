
#include "std_testcase.h"

#include <wchar.h>



void CWE476_NULL_Pointer_Dereference__char_66b_badSink(char * dataArray[])
{
    
    char * data = dataArray[2];
    
    
    printf("%02x\n", data[0]);
}






void CWE476_NULL_Pointer_Dereference__char_66b_cwe_fooSink(char * dataArray[])
{
    char * data = dataArray[2];
    
    
    printf("%02x\n", data[0]);
}


void CWE476_NULL_Pointer_Dereference__char_66b_cwe_barSink(char * dataArray[])
{
    char * data = dataArray[2];
    
    if (data != NULL)
    {
        
        printf("%02x\n", data[0]);
    }
    else
    {
        printLine("data is NULL");
    }
}


