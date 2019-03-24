
#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)



void testset1_15_foo()
{
    int data;
    
    data = -1;
    switch(6)
    {
    case 6:
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
    break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
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
    break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}






static void cwe_bar1()
{
    int data;
    
    data = -1;
    switch(6)
    {
    case 6:
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
    break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(8)
    {
    case 7:
        
        printLine("Benign, fixed string");
        break;
    default:
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
    break;
    }
}


static void cwe_bar2()
{
    int data;
    
    data = -1;
    switch(6)
    {
    case 6:
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
    break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
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
    break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}


static void cwe_bar3()
{
    int data;
    
    data = -1;
    switch(6)
    {
    case 6:
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
    break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 6:
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
    break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}


static void cwe_foo1()
{
    int data;
    
    data = -1;
    switch(5)
    {
    case 6:
        
        printLine("Benign, fixed string");
        break;
    default:
        

        data = 7;
        break;
    }
    switch(7)
    {
    case 7:
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
    break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}


static void cwe_foo2()
{
    int data;
    
    data = -1;
    switch(6)
    {
    case 6:
        

        data = 7;
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
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
    break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}

void testset1_15_bar()
{
    cwe_bar1();
    cwe_bar2();
    cwe_bar3();
    cwe_foo1();
    cwe_foo2();
}



