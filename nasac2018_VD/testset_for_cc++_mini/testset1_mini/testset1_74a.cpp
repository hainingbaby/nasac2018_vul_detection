
#include "std_testcase.h"
#include <map>

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

using namespace std;

namespace testset1_74
{




void foo_barSink(map<int, int> dataMap);

void foo_bar()
{
    int data;
    map<int, int> dataMap;
    
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
    
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    foo_barSink(dataMap);
}






void cwe_fooSink(map<int, int> dataMap);

static void cwe_foo()
{
    int data;
    map<int, int> dataMap;
    
    data = -1;
    

    data = 7;
    
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    cwe_fooSink(dataMap);
}


void cwe_barSink(map<int, int> dataMap);

static void cwe_bar()
{
    int data;
    map<int, int> dataMap;
    
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

