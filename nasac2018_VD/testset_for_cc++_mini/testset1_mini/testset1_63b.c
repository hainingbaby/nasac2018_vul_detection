
#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)



void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_63b_badSink(int * dataPtr)
{
    int data = *dataPtr;
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






void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_63b_cwe_fooSink(int * dataPtr)
{
    int data = *dataPtr;
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


void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_63b_cwe_barSink(int * dataPtr)
{
    int data = *dataPtr;
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


