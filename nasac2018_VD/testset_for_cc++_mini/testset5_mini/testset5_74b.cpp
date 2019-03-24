
#include "std_testcase.h"
#include <map>

using namespace std;

namespace testset5_74
{



void foo_barSink(map<int, int *> dataMap)
{
    
    int * data = dataMap[2];
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






void cwe_fooSink(map<int, int *> dataMap)
{
    int * data = dataMap[2];
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
