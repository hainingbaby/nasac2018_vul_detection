
#include "std_testcase.h"

#include <wchar.h>



void CWE476_NULL_Pointer_Dereference__char_64b_badSink(void * dataVoidPtr)
{
    
    char * * dataPtr = (char * *)dataVoidPtr;
    
    char * data = (*dataPtr);
    
    
    printf("%02x\n", data[0]);
}






void CWE476_NULL_Pointer_Dereference__char_64b_cwe_fooSink(void * dataVoidPtr)
{
    
    char * * dataPtr = (char * *)dataVoidPtr;
    
    char * data = (*dataPtr);
    
    
    printf("%02x\n", data[0]);
}


void CWE476_NULL_Pointer_Dereference__char_64b_cwe_barSink(void * dataVoidPtr)
{
    
    char * * dataPtr = (char * *)dataVoidPtr;
    
    char * data = (*dataPtr);
    
    if (data != NULL)
    {
        
        printf("%02x\n", data[0]);
    }
    else
    {
        printLine("data is NULL");
    }
}


