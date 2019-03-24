
#include "std_testcase.h"
#include <map>

using namespace std;

namespace testset5_74
{




void foo_barSink(map<int, int *> dataMap);

void foo_bar()
{
    int * data;
    map<int, int *> dataMap;
    data = NULL;
    
    data = (int *)malloc(10);
    
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    foo_barSink(dataMap);
}








void cwe_fooSink(map<int, int *> dataMap);

static void cwe_foo()
{
    int * data;
    map<int, int *> dataMap;
    data = NULL;
    
    data = (int *)malloc(10*sizeof(int));
    
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    cwe_fooSink(dataMap);
}

void good()
{
    cwe_foo();
}



} 

