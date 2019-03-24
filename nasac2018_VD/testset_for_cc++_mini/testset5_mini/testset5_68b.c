
#include "std_testcase.h"

extern int * testset5_68b_fooData;
extern int * CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68_cwe_fooData;





void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68b_badSink()
{
    int * data = testset5_68b_fooData;
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






void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68b_cwe_fooSink()
{
    int * data = CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68_cwe_fooData;
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


