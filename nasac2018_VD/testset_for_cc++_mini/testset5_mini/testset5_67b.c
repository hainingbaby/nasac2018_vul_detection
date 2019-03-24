
#include "std_testcase.h"

typedef struct _CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_structType
{
    int * structFirst;
} CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_structType;



void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67b_badSink(CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_structType myStruct)
{
    int * data = myStruct.structFirst;
    {
        int source[10] = {0};
        size_t i;
        
        for (i = 0; i < 10; i++)
        {
            data[i] = source[i];
        }
        printIntLine(data[0]);
        free(data);
    }
}






void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67b_cwe_fooSink(CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_structType myStruct)
{
    int * data = myStruct.structFirst;
    {
        int source[10] = {0};
        size_t i;
        
        for (i = 0; i < 10; i++)
        {
            data[i] = source[i];
        }
        printIntLine(data[0]);
        free(data);
    }
}


