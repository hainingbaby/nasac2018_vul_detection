
#include "std_testcase.h"
#include <list>

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

using namespace std;

namespace testset1_73
{




void foo_barSink(list<int> dataList);

void foo_bar()
{
    int data;
    list<int> dataList;
    
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
    
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    foo_barSink(dataList);
}






void cwe_fooSink(list<int> dataList);

static void cwe_foo()
{
    int data;
    list<int> dataList;
    
    data = -1;
    

    data = 7;
    
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    cwe_fooSink(dataList);
}


void cwe_barSink(list<int> dataList);

static void cwe_bar()
{
    int data;
    list<int> dataList;
    
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

