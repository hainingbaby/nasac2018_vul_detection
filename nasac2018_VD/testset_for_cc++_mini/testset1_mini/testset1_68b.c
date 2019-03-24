
#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

extern int testset1_68b_fooData;
extern int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_68_cwe_fooData;
extern int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_68_cwe_barData;



void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_68b_badSink()
{
    int data = testset1_68b_fooData;
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






void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_68b_cwe_fooSink()
{
    int data = CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_68_cwe_fooData;
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


void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_68b_cwe_barSink()
{
    int data = CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_68_cwe_barData;
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


