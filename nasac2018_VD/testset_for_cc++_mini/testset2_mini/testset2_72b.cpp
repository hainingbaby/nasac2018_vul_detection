
#include "std_testcase.h"
#include <vector>

#include <wchar.h>

using namespace std;

namespace testset2_72
{



void foo_barSink(vector<char *> dataVector)
{
    
    char * data = dataVector[2];
    
    free(data);
}






void cwe_fooSink(vector<char *> dataVector)
{
    char * data = dataVector[2];
    
    free(data);
}


void cwe_barSink(vector<char *> dataVector)
{
    char * data = dataVector[2];
    
    
    ; 
}



} 
