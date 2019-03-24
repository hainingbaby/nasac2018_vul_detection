
#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)



void testset1_12_foo()
{
    int data;
    
    data = -1;
    if(globalReturnsTrueOrFalse())
    {
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
    }
    else
    {
        

        data = 7;
    }
    if(globalReturnsTrueOrFalse())
    {
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
    else
    {
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







static void cwe_bar()
{
    int data;
    
    data = -1;
    if(globalReturnsTrueOrFalse())
    {
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
    }
    else
    {
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
    }
    if(globalReturnsTrueOrFalse())
    {
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
    else
    {
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



static void cwe_foo()
{
    int data;
    
    data = -1;
    if(globalReturnsTrueOrFalse())
    {
        

        data = 7;
    }
    else
    {
        

        data = 7;
    }
    if(globalReturnsTrueOrFalse())
    {
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
    else
    {
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

void testset1_12_bar()
{
    cwe_bar();
    cwe_foo();
}



