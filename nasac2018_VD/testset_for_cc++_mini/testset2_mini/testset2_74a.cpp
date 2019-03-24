
#include "std_testcase.h"
#include <map>

#include <wchar.h>

using namespace std;

namespace testset2_74
{




void foo_barSink(map<int, char *> dataMap);

void foo_bar()
{
    char * data;
    map<int, char *> dataMap;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    
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
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    
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
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
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

