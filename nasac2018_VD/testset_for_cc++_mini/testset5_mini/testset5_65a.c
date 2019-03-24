
#include "std_testcase.h"




void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_65b_badSink(int * data);

void testset5_65a_foo()
{
    int * data;
    
    void (*funcPtr) (int *) = CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_65b_badSink;
    data = NULL;
    
    data = (int *)malloc(10);
    
    funcPtr(data);
}






void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_65b_cwe_fooSink(int * data);

static void cwe_foo()
{
    int * data;
    void (*funcPtr) (int *) = CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_65b_cwe_fooSink;
    data = NULL;
    
    data = (int *)malloc(10*sizeof(int));
    funcPtr(data);
}

void testset5_65a_bar()
{
    cwe_foo();
}



