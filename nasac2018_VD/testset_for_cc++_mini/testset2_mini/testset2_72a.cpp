
#include "std_testcase.h"
#include <vector>

#include <wchar.h>

using namespace std;

namespace testset2_72
{




void foo_barSink(vector<char *> dataVector);

void foo_bar()
{
    char * data;
    vector<char *> dataVector;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    
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
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    
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
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
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

