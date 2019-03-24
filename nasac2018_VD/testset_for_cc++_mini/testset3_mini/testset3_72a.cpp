
#include "std_testcase.h"
#include <vector>

#include <wchar.h>

using namespace std;

namespace testset3_72
{




void foo_barSink(vector<char *> dataVector);

void foo_bar()
{
    char * data;
    vector<char *> dataVector;
    
    data = NULL;
    
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    foo_barSink(dataVector);
}






void cwe_fooSink(vector<char *> dataVector);

static void cwe_foo()
{
    char * data;
    vector<char *> dataVector;
    
    data = "Good";
    
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    cwe_fooSink(dataVector);
}


void cwe_barSink(vector<char *> dataVector);

static void cwe_bar()
{
    char * data;
    vector<char *> dataVector;
    
    data = NULL;
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    cwe_barSink(dataVector);
}

void good()
{
    cwe_foo();
    cwe_bar();
}



} 

