
#include "std_testcase.h"



void testset5_17_foo()
{
    int i;
    int * data;
    data = NULL;
    for(i = 0; i < 1; i++)
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






static void cwe_foo()
{
    int h;
    int * data;
    data = NULL;
    for(h = 0; h < 1; h++)
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

void testset5_17_bar()
{
    cwe_foo();
}



