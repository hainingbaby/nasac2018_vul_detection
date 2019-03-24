
#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)



void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_66b_badSink(int dataArray[])
{
    
    int data = dataArray[2];
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






void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_66b_cwe_fooSink(int dataArray[])
{
    int data = dataArray[2];
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


void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_66b_cwe_barSink(int dataArray[])
{
    int data = dataArray[2];
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

