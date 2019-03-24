
#include "std_testcase.h"





void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_53d_badSink(int * data)
{
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






void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_53d_cwe_fooSink(int * data)
{
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


