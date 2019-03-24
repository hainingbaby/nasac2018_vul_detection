
#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)



static int badSource(int data)
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
    return data;
}

void testset1_42_foo()
{
    int data;
    
    data = -1;
    data = badSource(data);
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






static int cwe_fooSource(int data)
{
    

    data = 7;
    return data;
}

static void cwe_foo()
{
    int data;
    
    data = -1;
    data = cwe_fooSource(data);
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


static int cwe_barSource(int data)
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
    return data;
}

static void cwe_bar()
{
    int data;
    
    data = -1;
    data = cwe_barSource(data);
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

void testset1_42_bar()
{
    cwe_bar();
    cwe_foo();
}



