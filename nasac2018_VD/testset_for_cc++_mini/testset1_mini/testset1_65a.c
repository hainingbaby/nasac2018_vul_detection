
#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)




void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_65b_badSink(int data);

void testset1_65a_foo()
{
    int data;
    
    void (*funcPtr) (int) = CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_65b_badSink;
    
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
    
    funcPtr(data);
}






void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_65b_cwe_fooSink(int data);

static void cwe_foo()
{
    int data;
    void (*funcPtr) (int) = CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_65b_cwe_fooSink;
    
    data = -1;
    

    data = 7;
    funcPtr(data);
}


void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_65b_cwe_barSink(int data);

static void cwe_bar()
{
    int data;
    void (*funcPtr) (int) = CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_65b_cwe_barSink;
    
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
    funcPtr(data);
}

void testset1_65a_bar()
{
    cwe_foo();
    cwe_bar();
}



