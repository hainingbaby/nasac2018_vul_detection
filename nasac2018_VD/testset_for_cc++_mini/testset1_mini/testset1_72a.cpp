
#include "std_testcase.h"
#include <vector>

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

using namespace std;

namespace testset1_72
{




void foo_barSink(vector<int> dataVector);

void foo_bar()
{
    int data;
    vector<int> dataVector;
    
    data = -1;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            
            data = atoi(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
    
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    foo_barSink(dataVector);
}






void cwe_fooSink(vector<int> dataVector);

static void cwe_foo()
{
    int data;
    vector<int> dataVector;
    
    data = -1;
    

    data = 7;
    
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    cwe_fooSink(dataVector);
}


void cwe_barSink(vector<int> dataVector);

static void cwe_bar()
{
    int data;
    vector<int> dataVector;
    
    data = -1;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            
            data = atoi(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
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

