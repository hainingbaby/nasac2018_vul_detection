
#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)




void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_52b_badSink(int data);

void testset1_52a_foo()
{
    int data;
    
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
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_52b_badSink(data);
}






void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_52b_cwe_fooSink(int data);

static void cwe_foo()
{
    int data;
    
    data = -1;
    

    data = 7;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_52b_cwe_fooSink(data);
}


void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_52b_cwe_barSink(int data);

static void cwe_bar()
{
    int data;
    
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
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_52b_cwe_barSink(data);
}

void testset1_52a_bar()
{
    cwe_foo();
    cwe_bar();
}



