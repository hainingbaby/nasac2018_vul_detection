
#include "std_testcase.h"




int * CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_61b_badSource(int * data);

void testset5_61a_foo()
{
    int * data;
    data = NULL;
    data = CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_61b_badSource(data);
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






int * CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_61b_cwe_fooSource(int * data);

static void cwe_foo()
{
    int * data;
    data = NULL;
    data = CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_61b_cwe_fooSource(data);
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

void testset5_61a_bar()
{
    cwe_foo();
}



