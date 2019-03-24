
#include "std_testcase.h"
#include "testset5_84.h"

namespace testset5_84
{
testset5_84_foo::testset5_84_foo(int * dataCopy)
{
    data = dataCopy;
    
    data = (int *)malloc(10*sizeof(int));
}

testset5_84_foo::~testset5_84_foo()
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
}

