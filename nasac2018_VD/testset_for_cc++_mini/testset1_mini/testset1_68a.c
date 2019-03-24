
#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

int testset1_68a_fooData;
int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_68_cwe_fooData;
int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_68_cwe_barData;




void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_68b_badSink();

void testset1_68a_foo()
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
    testset1_68a_fooData = data;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_68b_badSink();
}






void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_68b_cwe_fooSink();
void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_68b_cwe_barSink();


static void cwe_foo()
{
    int data;
    
    data = -1;
    

    data = 7;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_68_cwe_fooData = data;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_68b_cwe_fooSink();
}


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
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_68_cwe_barData = data;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_68b_cwe_barSink();
}

void testset1_68a_bar()
{
    cwe_foo();
    cwe_bar();
}



