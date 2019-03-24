
#include "std_testcase.h"



void testset5_15_foo()
{
    int * data;
    data = NULL;
    switch(6)
    {
    case 6:
        
        data = (int *)malloc(10);
        break;
    default:
        
        printLine("Benign, fixed string");
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






static void cwe_foo1()
{
    int * data;
    data = NULL;
    switch(5)
    {
    case 6:
        
        printLine("Benign, fixed string");
        break;
    default:
        
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


static void cwe_foo2()
{
    int * data;
    data = NULL;
    switch(6)
    {
    case 6:
        
        data = (int *)malloc(10*sizeof(int));
        break;
    default:
        
        printLine("Benign, fixed string");
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

void testset5_15_bar()
{
    cwe_foo1();
    cwe_foo2();
}



