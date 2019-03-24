
#include "std_testcase.h"




int testset5_22a_fooGlobal = 0;

int * testset5_22a_fooSource(int * data);

void testset5_22a_foo()
{
    int * data;
    data = NULL;
    testset5_22a_fooGlobal = 1; 
    data = testset5_22a_fooSource(data);
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






int CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_22_cwe_foo1Global = 0;
int CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_22_cwe_foo2Global = 0;


int * CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_22_cwe_foo1Source(int * data);

static void cwe_foo1()
{
    int * data;
    data = NULL;
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_22_cwe_foo1Global = 0; 
    data = CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_22_cwe_foo1Source(data);
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


int * CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_22_cwe_foo2Source(int * data);

static void cwe_foo2()
{
    int * data;
    data = NULL;
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_22_cwe_foo2Global = 1; 
    data = CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_22_cwe_foo2Source(data);
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

void testset5_22a_bar()
{
    cwe_foo1();
    cwe_foo2();
}



