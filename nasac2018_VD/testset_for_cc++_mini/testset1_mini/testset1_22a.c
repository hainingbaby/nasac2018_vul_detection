
#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)




int testset1_22a_fooGlobal = 0;

void testset1_22a_fooSink(int data);

void testset1_22a_foo()
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
    testset1_22a_fooGlobal = 1; 
    testset1_22a_fooSink(data);
}






int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar1Global = 0;
int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar2Global = 0;
int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar3Global = 0;
int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_fooGlobal = 0;


void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar1Sink(int data);

static void cwe_bar1()
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
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar1Global = 0; 
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar1Sink(data);
}


void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar2Sink(int data);

static void cwe_bar2()
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
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar2Global = 1; 
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar2Sink(data);
}


void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar3Sink(int data);

static void cwe_bar3()
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
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar3Global = 0; 
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar3Sink(data);
}


void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_fooSink(int data);

static void cwe_foo()
{
    int data;
    
    data = -1;
    

    data = 7;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_fooGlobal = 1; 
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_fooSink(data);
}

void testset1_22a_bar()
{
    cwe_bar1();
    cwe_bar2();
    cwe_bar3();
    cwe_foo();
}



