
#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)



int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_61b_badSource(int data)
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






int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_61b_cwe_fooSource(int data)
{
    

    data = 7;
    return data;
}


int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_61b_cwe_barSource(int data)
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


