
#include "std_testcase.h"
#include <vector>

#include <wchar.h>

using namespace std;

namespace testset3_72
{



void foo_barSink(vector<char *> dataVector)
{
    
    char * data = dataVector[2];
    
    
    printf("%02x\n", data[0]);
}






void cwe_fooSink(vector<char *> dataVector)
{
    char * data = dataVector[2];
    
    
    printf("%02x\n", data[0]);
}


void cwe_barSink(vector<char *> dataVector)
{
    char * data = dataVector[2];
    
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
