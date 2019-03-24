
#include "std_testcase.h"

typedef struct _CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_structType
{
    int * structFirst;
} CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_structType;




void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67b_badSink(CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_structType myStruct);

void testset5_67a_foo()
{
    int * data;
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_structType myStruct;
    data = NULL;
    
    data = (int *)malloc(10);
    myStruct.structFirst = data;
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67b_badSink(myStruct);
}






void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67b_cwe_fooSink(CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_structType myStruct);

static void cwe_foo()
{
    int * data;
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_structType myStruct;
    data = NULL;
    
    data = (int *)malloc(10*sizeof(int));
    myStruct.structFirst = data;
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67b_cwe_fooSink(myStruct);
}

void testset5_67a_bar()
{
    cwe_foo();
}



