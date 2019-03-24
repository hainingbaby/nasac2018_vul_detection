
#include "std_testcase.h"



void testset5_14_foo()
{
    int * data;
    data = NULL;
    if(globalFive==5)
    {
        
        data = (int *)malloc(10);
    }
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






static void cwe_foo1()
{
    int * data;
    data = NULL;
    if(globalFive!=5)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = (int *)malloc(10*sizeof(int));
    }
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


static void cwe_foo2()
{
    int * data;
    data = NULL;
    if(globalFive==5)
    {
        
        data = (int *)malloc(10*sizeof(int));
    }
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

void testset5_14_bar()
{
    cwe_foo1();
    cwe_foo2();
}



