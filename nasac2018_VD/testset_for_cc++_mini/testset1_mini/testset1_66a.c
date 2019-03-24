
#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)




void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_66b_badSink(int dataArray[]);

void testset1_66a_foo()
{
    int data;
    int dataArray[5];
    
    data = -1;
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
    
    dataArray[2] = data;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_66b_badSink(dataArray);
}






void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_66b_cwe_fooSink(int dataArray[]);

static void cwe_foo()
{
    int data;
    int dataArray[5];
    
    data = -1;
    

    data = 7;
    dataArray[2] = data;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_66b_cwe_fooSink(dataArray);
}


void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_66b_cwe_barSink(int dataArray[]);

static void cwe_bar()
{
    int data;
    int dataArray[5];
    
    data = -1;
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
    dataArray[2] = data;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_66b_cwe_barSink(dataArray);
}

void testset1_66a_bar()
{
    cwe_foo();
    cwe_bar();
}



