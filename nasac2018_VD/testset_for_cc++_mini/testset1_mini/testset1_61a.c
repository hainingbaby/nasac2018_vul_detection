
#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)




int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_61b_badSource(int data);

void testset1_61a_foo()
{
    int data;
    
    data = -1;
    data = CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_61b_badSource(data);
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






int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_61b_cwe_fooSource(int data);

static void cwe_foo()
{
    int data;
    
    data = -1;
    data = CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_61b_cwe_fooSource(data);
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


int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_61b_cwe_barSource(int data);

static void cwe_bar()
{
    int data;
    
    data = -1;
    data = CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_61b_cwe_barSource(data);
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

void testset1_61a_bar()
{
    cwe_foo();
    cwe_bar();
}



