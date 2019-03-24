
#include "std_testcase.h"
#include <map>

#include <wchar.h>

using namespace std;

namespace testset3_74
{




void foo_barSink(map<int, char *> dataMap);

void foo_bar()
{
    char * data;
    map<int, char *> dataMap;
    
    data = NULL;
    
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    foo_barSink(dataMap);
}






void cwe_fooSink(map<int, char *> dataMap);

static void cwe_foo()
{
    char * data;
    map<int, char *> dataMap;
    
    data = "Good";
    
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    cwe_fooSink(dataMap);
}


void cwe_barSink(map<int, char *> dataMap);

static void cwe_bar()
{
    char * data;
    map<int, char *> dataMap;
    
    data = NULL;
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    cwe_barSink(dataMap);
}

void good()
{
    cwe_foo();
    cwe_bar();
}



} 

