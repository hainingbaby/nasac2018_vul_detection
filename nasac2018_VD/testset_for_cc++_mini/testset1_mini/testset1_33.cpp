
#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

namespace testset1_33
{



void foo_bar()
{
    int data;
    int &dataRef = data;
    
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
    {
        int data = dataRef;
        {
            int i;
            int buffer[10] = { 0 };
            

            if (data >= 0)
            {
                buffer[data] = 1;
                
                for(i = 0; i < 10; i++)
                {
                    printIntLine(buffer[i]);
                }
            }
            else
            {
                printLine("ERROR: Array index is negative.");
            }
        }
    }
}






static void cwe_foo()
{
    int data;
    int &dataRef = data;
    
    data = -1;
    

    data = 7;
    {
        int data = dataRef;
        {
            int i;
            int buffer[10] = { 0 };
            

            if (data >= 0)
            {
                buffer[data] = 1;
                
                for(i = 0; i < 10; i++)
                {
                    printIntLine(buffer[i]);
                }
            }
            else
            {
                printLine("ERROR: Array index is negative.");
            }
        }
    }
}


static void cwe_bar()
{
    int data;
    int &dataRef = data;
    
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
    {
        int data = dataRef;
        {
            int i;
            int buffer[10] = { 0 };
            
            if (data >= 0 && data < (10))
            {
                buffer[data] = 1;
                
                for(i = 0; i < 10; i++)
                {
                    printIntLine(buffer[i]);
                }
            }
            else
            {
                printLine("ERROR: Array index is out-of-bounds");
            }
        }
    }
}

void good()
{
    cwe_foo();
    cwe_bar();
}



} 

