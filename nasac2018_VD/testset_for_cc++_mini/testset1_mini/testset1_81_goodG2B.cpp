
#include "std_testcase.h"
#include "testset1_81.h"

namespace testset1_81
{

void testset1_81_foo::action(int data) const
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

