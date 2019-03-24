
#include "std_testcase.h"



void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_64b_badSink(void * dataVoidPtr)
{
    
    int * * dataPtr = (int * *)dataVoidPtr;
    
    int * data = (*dataPtr);
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






void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_64b_cwe_fooSink(void * dataVoidPtr)
{
    
    int * * dataPtr = (int * *)dataVoidPtr;
    
    int * data = (*dataPtr);
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


