
#include "std_testcase.h"




void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_64b_badSink(void * dataVoidPtr);

void testset5_64a_foo()
{
    int * data;
    data = NULL;
    
    data = (int *)malloc(10);
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_64b_badSink(&data);
}






void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_64b_cwe_fooSink(void * dataVoidPtr);

static void cwe_foo()
{
    int * data;
    data = NULL;
    
    data = (int *)malloc(10*sizeof(int));
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_64b_cwe_fooSink(&data);
}

void testset5_64a_bar()
{
    cwe_foo();
}



