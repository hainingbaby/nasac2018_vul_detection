
#include "std_testcase.h"
#include "testset5_81.h"

namespace testset5_81
{

void testset5_81_foo_bar::action(int * data) const
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

