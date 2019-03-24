
#include "std_testcase.h"
#include <vector>

using namespace std;

namespace testset5_72
{



void foo_barSink(vector<int *> dataVector)
{
    
    int * data = dataVector[2];
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






void cwe_fooSink(vector<int *> dataVector)
{
    int * data = dataVector[2];
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
