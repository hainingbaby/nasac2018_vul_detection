
#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)




static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}



void testset1_08_foo()
{
    int data;
    
    data = -1;
    if(staticReturnsTrue())
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
    if(staticReturnsTrue())
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






static void cwe_bar1()
{
    int data;
    
    data = -1;
    if(staticReturnsTrue())
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
    if(staticReturnsFalse())
    {
        
        printLine("Benign, fixed string");
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


static void cwe_bar2()
{
    int data;
    
    data = -1;
    if(staticReturnsTrue())
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
    if(staticReturnsTrue())
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


static void cwe_bar3()
{
    int data;
    
    data = -1;
    if(staticReturnsTrue())
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
    if(staticReturnsFalse())
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


static void cwe_foo1()
{
    int data;
    
    data = -1;
    if(staticReturnsFalse())
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        

        data = 7;
    }
    if(staticReturnsTrue())
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


static void cwe_foo2()
{
    int data;
    
    data = -1;
    if(staticReturnsTrue())
    {
        

        data = 7;
    }
    if(staticReturnsTrue())
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

void testset1_08_bar()
{
    cwe_bar1();
    cwe_bar2();
    cwe_bar3();
    cwe_foo1();
    cwe_foo2();
}



