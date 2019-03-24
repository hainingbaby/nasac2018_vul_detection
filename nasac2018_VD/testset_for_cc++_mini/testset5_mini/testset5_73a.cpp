
#include "std_testcase.h"
#include <list>

using namespace std;

namespace testset5_73
{




void foo_barSink(list<int *> dataList);

void foo_bar()
{
    int * data;
    list<int *> dataList;
    data = NULL;
    
    data = (int *)malloc(10);
    
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    foo_barSink(dataList);
}








void cwe_fooSink(list<int *> dataList);

static void cwe_foo()
{
    int * data;
    list<int *> dataList;
    data = NULL;
    
    data = (int *)malloc(10*sizeof(int));
    
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    cwe_fooSink(dataList);
}

void good()
{
    cwe_foo();
}



} 

