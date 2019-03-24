
#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)



void testset1_32_foo()
{
    int data;
    int *dataPtr1 = &data;
    int *dataPtr2 = &data;
    
    data = -1;
    {
        int data = *dataPtr1;
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
        *dataPtr1 = data;
    }
    {
        int data = *dataPtr2;
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
    int *dataPtr1 = &data;
    int *dataPtr2 = &data;
    
    data = -1;
    {
        int data = *dataPtr1;
        

        data = 7;
        *dataPtr1 = data;
    }
    {
        int data = *dataPtr2;
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
    int *dataPtr1 = &data;
    int *dataPtr2 = &data;
    
    data = -1;
    {
        int data = *dataPtr1;
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
        *dataPtr1 = data;
    }
    {
        int data = *dataPtr2;
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

void testset1_32_bar()
{
    cwe_foo();
    cwe_bar();
}



