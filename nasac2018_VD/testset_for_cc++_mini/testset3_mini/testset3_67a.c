
#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE476_NULL_Pointer_Dereference__char_67_structType
{
    char * structFirst;
} CWE476_NULL_Pointer_Dereference__char_67_structType;




void CWE476_NULL_Pointer_Dereference__char_67b_badSink(CWE476_NULL_Pointer_Dereference__char_67_structType myStruct);

void testset3_67a_foo()
{
    char * data;
    CWE476_NULL_Pointer_Dereference__char_67_structType myStruct;
    
    data = NULL;
    myStruct.structFirst = data;
    CWE476_NULL_Pointer_Dereference__char_67b_badSink(myStruct);
}






void CWE476_NULL_Pointer_Dereference__char_67b_cwe_fooSink(CWE476_NULL_Pointer_Dereference__char_67_structType myStruct);

static void cwe_foo()
{
    char * data;
    CWE476_NULL_Pointer_Dereference__char_67_structType myStruct;
    
    data = "Good";
    myStruct.structFirst = data;
    CWE476_NULL_Pointer_Dereference__char_67b_cwe_fooSink(myStruct);
}


void CWE476_NULL_Pointer_Dereference__char_67b_cwe_barSink(CWE476_NULL_Pointer_Dereference__char_67_structType myStruct);

static void cwe_bar()
{
    char * data;
    CWE476_NULL_Pointer_Dereference__char_67_structType myStruct;
    
    data = NULL;
    myStruct.structFirst = data;
    CWE476_NULL_Pointer_Dereference__char_67b_cwe_barSink(myStruct);
}

void testset3_67a_bar()
{
    cwe_foo();
    cwe_bar();
}



