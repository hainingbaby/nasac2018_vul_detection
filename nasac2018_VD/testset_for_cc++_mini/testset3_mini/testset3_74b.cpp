
#include "std_testcase.h"
#include <map>

#include <wchar.h>

using namespace std;

namespace testset3_74
{



void foo_barSink(map<int, char *> dataMap)
{
    
    char * data = dataMap[2];
    
    
    printf("%02x\n", data[0]);
}






void cwe_fooSink(map<int, char *> dataMap)
{
    char * data = dataMap[2];
    
    
    printf("%02x\n", data[0]);
}


void cwe_barSink(map<int, char *> dataMap)
{
    char * data = dataMap[2];
    
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
