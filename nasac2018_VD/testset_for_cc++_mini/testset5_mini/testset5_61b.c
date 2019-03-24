
#include "std_testcase.h"



int * CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_61b_badSource(int * data)
{
    
    data = (int *)malloc(10);
    return data;
}






int * CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_61b_cwe_fooSource(int * data)
{
    
    data = (int *)malloc(10*sizeof(int));
    return data;
}


