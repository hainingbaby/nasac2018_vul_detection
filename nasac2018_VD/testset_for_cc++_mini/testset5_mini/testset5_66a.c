
#include "std_testcase.h"




void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_66b_badSink(int * dataArray[]);

void testset5_66a_foo()
{
    int * data;
    int * dataArray[5];
    data = NULL;
    
    data = (int *)malloc(10);
    
    dataArray[2] = data;
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_66b_badSink(dataArray);
}






void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_66b_cwe_fooSink(int * dataArray[]);

static void cwe_foo()
{
    int * data;
    int * dataArray[5];
    data = NULL;
    
    data = (int *)malloc(10*sizeof(int));
    dataArray[2] = data;
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_66b_cwe_fooSink(dataArray);
}

void testset5_66a_bar()
{
    cwe_foo();
}



