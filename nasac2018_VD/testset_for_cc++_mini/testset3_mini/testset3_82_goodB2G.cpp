
#include "std_testcase.h"
#include "testset3_82.h"

namespace testset3_82
{

void testset3_82_bar::action(char * data)
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

