
#include "std_testcase.h"
#include "testset1_82.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

namespace testset1_82
{



void foo_bar()
{
    int data;
    
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
    testset1_82_base* baseObject = new testset1_82_foo_bar;
    baseObject->action(data);
    delete baseObject;
}






static void cwe_foo()
{
    int data;
    
    data = -1;
    

    data = 7;
    testset1_82_base* baseObject = new testset1_82_foo;
    baseObject->action(data);
    delete baseObject;
}


static void cwe_bar()
{
    int data;
    
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
    testset1_82_base* baseObject = new testset1_82_bar;
    baseObject->action(data);
    delete baseObject;
}

void good()
{
    cwe_foo();
    cwe_bar();
}



} 

