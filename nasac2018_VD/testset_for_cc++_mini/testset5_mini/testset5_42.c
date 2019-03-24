
#include "std_testcase.h"



static int * badSource(int * data)
{
    
    data = (int *)malloc(10);
    return data;
}

void testset5_42_foo()
{
    int * data;
    data = NULL;
    data = badSource(data);
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





static int * cwe_fooSource(int * data)
{
    
    data = (int *)malloc(10*sizeof(int));
    return data;
}


static void cwe_foo()
{
    int * data;
    data = NULL;
    data = cwe_fooSource(data);
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

void testset5_42_bar()
{
    cwe_foo();
}



