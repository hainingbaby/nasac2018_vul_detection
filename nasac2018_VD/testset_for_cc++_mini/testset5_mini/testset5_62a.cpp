
#include "std_testcase.h"

namespace testset5_62
{




void foo_barSource(int * &data);

void foo_bar()
{
    int * data;
    data = NULL;
    foo_barSource(data);
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






void cwe_fooSource(int * &data);

static void cwe_foo()
{
    int * data;
    data = NULL;
    cwe_fooSource(data);
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

void good()
{
    cwe_foo();
}



} 

