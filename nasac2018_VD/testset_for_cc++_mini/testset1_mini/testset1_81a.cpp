
#include "std_testcase.h"
#include "testset1_81.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

namespace testset1_81
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
    const testset1_81_base& baseObject = testset1_81_foo_bar();
    baseObject.action(data);
}






static void cwe_foo()
{
    int data;
    
    data = -1;
    

    data = 7;
    const testset1_81_base& baseObject = testset1_81_foo();
    baseObject.action(data);
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
    const testset1_81_base& baseObject = testset1_81_bar();
    baseObject.action(data);
}

void good()
{
    cwe_foo();
    cwe_bar();
}



} 

