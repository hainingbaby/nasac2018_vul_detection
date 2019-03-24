
#include "std_testcase.h"



void testset5_16_foo()
{
    int * data;
    data = NULL;
    while(1)
    {
        
        data = (int *)malloc(10);
        break;
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
    while(1)
    {
        
        data = (int *)malloc(10*sizeof(int));
        break;
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

void testset5_16_bar()
{
    cwe_foo();
}



