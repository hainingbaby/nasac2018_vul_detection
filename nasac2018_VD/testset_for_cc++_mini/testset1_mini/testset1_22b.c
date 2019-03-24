
#include "std_testcase.h"




extern int testset1_22b_fooGlobal;

void testset1_22b_fooSink(int data)
{
    if(testset1_22b_fooGlobal)
    {
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
}






extern int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar1Global;
extern int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar2Global;
extern int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar3Global;
extern int CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_fooGlobal;


void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar1Sink(int data)
{
    if(CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar1Global)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
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
}


void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar2Sink(int data)
{
    if(CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar2Global)
    {
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
}


void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar3Sink(int data)
{
    if(CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_bar3Global)
    {
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
}


void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_fooSink(int data)
{
    if(CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_22_cwe_fooGlobal)
    {
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
}


