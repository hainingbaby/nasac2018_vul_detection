
#include "std_testcase.h"
#include "testset1_84.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

namespace testset1_84
{
testset1_84_foo_bar::testset1_84_foo_bar(int dataCopy)
{
    data = dataCopy;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            
            data = atoi(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
}

testset1_84_foo_bar::~testset1_84_foo_bar()
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

