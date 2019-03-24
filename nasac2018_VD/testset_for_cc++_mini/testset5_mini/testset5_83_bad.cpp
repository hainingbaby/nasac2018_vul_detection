
#include "std_testcase.h"
#include "testset5_83.h"

namespace testset5_83
{
testset5_83_foo_bar::testset5_83_foo_bar(int * dataCopy)
{
    data = dataCopy;
    
    data = (int *)malloc(10);
}

testset5_83_foo_bar::~testset5_83_foo_bar()
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

