
#include "std_testcase.h"



void testset5_41_fooSink(int * data)
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

void testset5_41_foo()
{
    int * data;
    data = NULL;
    
    data = (int *)malloc(10);
    testset5_41_fooSink(data);
}





void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_41_cwe_fooSink(int * data)
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


static void cwe_foo()
{
    int * data;
    data = NULL;
    
    data = (int *)malloc(10*sizeof(int));
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_41_cwe_fooSink(data);
}

void testset5_41_bar()
{
    cwe_foo();
}



