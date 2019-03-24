
#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

typedef struct _CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_67_structType
{
    int structFirst;
} CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_67_structType;




void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_67b_badSink(CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_67_structType myStruct);

void testset1_67a_foo()
{
    int data;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_67_structType myStruct;
    
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
    myStruct.structFirst = data;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_67b_badSink(myStruct);
}






void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_67b_cwe_fooSink(CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_67_structType myStruct);

static void cwe_foo()
{
    int data;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_67_structType myStruct;
    
    data = -1;
    

    data = 7;
    myStruct.structFirst = data;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_67b_cwe_fooSink(myStruct);
}


void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_67b_cwe_barSink(CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_67_structType myStruct);

static void cwe_bar()
{
    int data;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_67_structType myStruct;
    
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
    myStruct.structFirst = data;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_67b_cwe_barSink(myStruct);
}

void testset1_67a_bar()
{
    cwe_foo();
    cwe_bar();
}



