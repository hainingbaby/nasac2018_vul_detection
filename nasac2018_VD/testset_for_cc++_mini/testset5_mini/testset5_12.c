
#include "std_testcase.h"



void testset5_12_foo()
{
    int * data;
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        
        data = (int *)malloc(10);
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







static void cwe_foo()
{
    int * data;
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        
        data = (int *)malloc(10*sizeof(int));
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

void testset5_12_bar()
{
    cwe_foo();
}



