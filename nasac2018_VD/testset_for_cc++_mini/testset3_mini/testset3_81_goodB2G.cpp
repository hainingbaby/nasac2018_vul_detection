
#include "std_testcase.h"
#include "testset3_81.h"

namespace testset3_81
{

void testset3_81_bar::action(char * data) const
{
    
    if (data != NULL)
    {
        
        printf("%02x\n", data[0]);
    }
    else
    {
        printLine("data is NULL");
    }
}

}

