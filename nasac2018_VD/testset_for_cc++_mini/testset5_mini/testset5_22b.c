
#include "std_testcase.h"




extern int testset5_22b_fooGlobal;

int * testset5_22b_fooSource(int * data)
{
    if(testset5_22b_fooGlobal)
    {
        
        data = (int *)malloc(10);
    }
    return data;
}






extern int CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_22_cwe_foo1Global;
extern int CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_22_cwe_foo2Global;


int * CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_22_cwe_foo1Source(int * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_22_cwe_foo1Global)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = (int *)malloc(10*sizeof(int));
    }
    return data;
}


int * CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_22_cwe_foo2Source(int * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_22_cwe_foo2Global)
    {
        
        data = (int *)malloc(10*sizeof(int));
    }
    return data;
}


