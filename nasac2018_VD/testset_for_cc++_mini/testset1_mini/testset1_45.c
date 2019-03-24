
#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

static int testset1_45_fooData;
static int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_45_cwe_fooData;
static int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_45_cwe_barData;



static void badSink()
{
    int data = testset1_45_fooData;
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

void testset1_45_foo()
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
    testset1_45_fooData = data;
    badSink();
}






static void cwe_fooSink()
{
    int data = CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_45_cwe_fooData;
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

static void cwe_foo()
{
    int data;
    
    data = -1;
    

    data = 7;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_45_cwe_fooData = data;
    cwe_fooSink();
}


static void cwe_barSink()
{
    int data = CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_45_cwe_barData;
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
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_45_cwe_barData = data;
    cwe_barSink();
}

void testset1_45_bar()
{
    cwe_foo();
    cwe_bar();
}



