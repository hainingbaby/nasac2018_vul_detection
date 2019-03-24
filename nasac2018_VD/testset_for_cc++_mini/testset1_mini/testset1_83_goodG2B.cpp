
#include "std_testcase.h"
#include "testset1_83.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

namespace testset1_83
{
testset1_83_foo::testset1_83_foo(int dataCopy)
{
    data = dataCopy;
    

    data = 7;
}

testset1_83_foo::~testset1_83_foo()
{
    {
        int i;
        int buffer[10] = { 0 };
        

        if (data >= 0)
        {
            buffer[data] = 1;
            
            for(i = 0; i < 10; i++)
            {
                printIntLine(buffer[i]);
            }
        }
        else
        {
            printLine("ERROR: Array index is negative.");
        }
    }
}
}

