
#include "std_testcase.h"
#include "testset5_82.h"

namespace testset5_82
{

void testset5_82_foo::action(int * data)
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

