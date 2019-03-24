
#include "std_testcase.h"

static int * testset5_45_fooData;
static int * CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_45_cwe_fooData;



static void badSink()
{
    int * data = testset5_45_fooData;
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

void testset5_45_foo()
{
    int * data;
    data = NULL;
    
    data = (int *)malloc(10);
    testset5_45_fooData = data;
    badSink();
}






static void cwe_fooSink()
{
    int * data = CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_45_cwe_fooData;
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
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_45_cwe_fooData = data;
    cwe_fooSink();
}

void testset5_45_bar()
{
    cwe_foo();
}



