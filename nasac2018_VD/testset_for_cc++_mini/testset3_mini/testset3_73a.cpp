
#include "std_testcase.h"
#include <list>

#include <wchar.h>

using namespace std;

namespace testset3_73
{




void foo_barSink(list<char *> dataList);

void foo_bar()
{
    char * data;
    list<char *> dataList;
    
    data = NULL;
    
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    foo_barSink(dataList);
}






void cwe_fooSink(list<char *> dataList);

static void cwe_foo()
{
    char * data;
    list<char *> dataList;
    
    data = "Good";
    
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    cwe_fooSink(dataList);
}


void cwe_barSink(list<char *> dataList);

static void cwe_bar()
{
    char * data;
    list<char *> dataList;
    
    data = NULL;
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    cwe_barSink(dataList);
}

void good()
{
    cwe_foo();
    cwe_bar();
}



} 

