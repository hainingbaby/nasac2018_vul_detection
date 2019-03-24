
#include "std_testcase.h"



static void badSink(int * data)
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

void testset5_44_foo()
{
    int * data;
    
    void (*funcPtr) (int *) = badSink;
    data = NULL;
    
    data = (int *)malloc(10);
    
    funcPtr(data);
}






static void cwe_fooSink(int * data)
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
    void (*funcPtr) (int *) = cwe_fooSink;
    data = NULL;
    
    data = (int *)malloc(10*sizeof(int));
    funcPtr(data);
}

void testset5_44_bar()
{
    cwe_foo();
}



