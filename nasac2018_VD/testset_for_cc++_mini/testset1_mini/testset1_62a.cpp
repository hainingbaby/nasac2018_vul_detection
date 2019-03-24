
#include "std_testcase.h"

namespace testset1_62
{




void foo_barSource(int &data);

void foo_bar()
{
    int data;
    
    data = -1;
    foo_barSource(data);
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






void cwe_fooSource(int &data);

static void cwe_foo()
{
    int data;
    
    data = -1;
    cwe_fooSource(data);
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


void cwe_barSource(int &data);

static void cwe_bar()
{
    int data;
    
    data = -1;
    cwe_barSource(data);
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

void good()
{
    cwe_foo();
    cwe_bar();
}



} 

