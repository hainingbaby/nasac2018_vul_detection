
#include "std_testcase.h"
#include <list>

#include <wchar.h>

using namespace std;

namespace testset3_73
{



void foo_barSink(list<char *> dataList)
{
    
    char * data = dataList.back();
    
    
    printf("%02x\n", data[0]);
}






void cwe_fooSink(list<char *> dataList)
{
    char * data = dataList.back();
    
    
    printf("%02x\n", data[0]);
}


void cwe_barSink(list<char *> dataList)
{
    char * data = dataList.back();
    
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
