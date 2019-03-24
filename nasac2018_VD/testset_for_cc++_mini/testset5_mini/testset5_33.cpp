
#include "std_testcase.h"

namespace testset5_33
{



void foo_bar()
{
    int * data;
    int * &dataRef = data;
    data = NULL;
    
    data = (int *)malloc(10);
    {
        int * data = dataRef;
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
    int * &dataRef = data;
    data = NULL;
    
    data = (int *)malloc(10*sizeof(int));
    {
        int * data = dataRef;
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

void good()
{
    cwe_foo();
}



} 

