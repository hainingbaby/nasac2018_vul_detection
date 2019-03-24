
#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE476_NULL_Pointer_Dereference__char_67_structType
{
    char * structFirst;
} CWE476_NULL_Pointer_Dereference__char_67_structType;



void CWE476_NULL_Pointer_Dereference__char_67b_badSink(CWE476_NULL_Pointer_Dereference__char_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    
    
    printf("%02x\n", data[0]);
}






void CWE476_NULL_Pointer_Dereference__char_67b_cwe_fooSink(CWE476_NULL_Pointer_Dereference__char_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    
    
    printf("%02x\n", data[0]);
}


void CWE476_NULL_Pointer_Dereference__char_67b_cwe_barSink(CWE476_NULL_Pointer_Dereference__char_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    
    if (data != NULL)
    {
        
        printf("%02x\n", data[0]);
    }
    else
    {
        printLine("data is NULL");
    }
}


