
#include "std_testcase.h"
#include <list>

#include <wchar.h>

using namespace std;

namespace testset2_73
{



void foo_barSink(list<char *> dataList)
{
    
    char * data = dataList.back();
    
    free(data);
}






void cwe_fooSink(list<char *> dataList)
{
    char * data = dataList.back();
    
    free(data);
}


void cwe_barSink(list<char *> dataList)
{
    char * data = dataList.back();
    
    
    ; 
}



} 
