
#include "std_testcase.h"



void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_66b_badSink(int * dataArray[])
{
    
    int * data = dataArray[2];
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






void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_66b_cwe_fooSink(int * dataArray[])
{
    int * data = dataArray[2];
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


