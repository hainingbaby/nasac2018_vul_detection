
#include "std_testcase.h"



void testset5_31_foo()
{
    int * data;
    data = NULL;
    
    data = (int *)malloc(10);
    {
        int * dataCopy = data;
        int * data = dataCopy;
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
}






static void cwe_foo()
{
    int * data;
    data = NULL;
    
    data = (int *)malloc(10*sizeof(int));
    {
        int * dataCopy = data;
        int * data = dataCopy;
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
}

void testset5_31_bar()
{
    cwe_foo();
}



