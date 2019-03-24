
#include "std_testcase.h"
#include <map>

#include <wchar.h>

using namespace std;

namespace testset2_74
{



void foo_barSink(map<int, char *> dataMap)
{
    
    char * data = dataMap[2];
    
    free(data);
}






void cwe_fooSink(map<int, char *> dataMap)
{
    char * data = dataMap[2];
    
    free(data);
}


void cwe_barSink(map<int, char *> dataMap)
{
    char * data = dataMap[2];
    
    
    ; 
}



} 
