
#include "std_testcase.h"
#include <list>

using namespace std;

namespace testset5_73
{



void foo_barSink(list<int *> dataList)
{
    
    int * data = dataList.back();
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






void cwe_fooSink(list<int *> dataList)
{
    int * data = dataList.back();
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
