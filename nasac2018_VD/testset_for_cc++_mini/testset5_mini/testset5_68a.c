
#include "std_testcase.h"

int * testset5_68a_fooData;
int * CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68_cwe_fooData;




void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68b_badSink();

void testset5_68a_foo()
{
    int * data;
    data = NULL;
    
    data = (int *)malloc(10);
    testset5_68a_fooData = data;
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68b_badSink();
}






void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68b_cwe_fooSink();


static void cwe_foo()
{
    int * data;
    data = NULL;
    
    data = (int *)malloc(10*sizeof(int));
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68_cwe_fooData = data;
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_68b_cwe_fooSink();
}

void testset5_68a_bar()
{
    cwe_foo();
}



