
#include "std_testcase.h"
#include <vector>

using namespace std;

namespace testset5_72
{




void foo_barSink(vector<int *> dataVector);

void foo_bar()
{
    int * data;
    vector<int *> dataVector;
    data = NULL;
    
    data = (int *)malloc(10);
    
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    foo_barSink(dataVector);
}








void cwe_fooSink(vector<int *> dataVector);

static void cwe_foo()
{
    int * data;
    vector<int *> dataVector;
    data = NULL;
    
    data = (int *)malloc(10*sizeof(int));
    
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    cwe_fooSink(dataVector);
}

void good()
{
    cwe_foo();
}



} 

