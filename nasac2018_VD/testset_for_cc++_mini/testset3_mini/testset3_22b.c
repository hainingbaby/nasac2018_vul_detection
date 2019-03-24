
#include "std_testcase.h"

#include <wchar.h>




extern int testset3_22b_fooGlobal;

void testset3_22b_fooSink(char * data)
{
    if(testset3_22b_fooGlobal)
    {
        
        
        printf("%02x\n", data[0]);
    }
}






extern int CWE476_NULL_Pointer_Dereference__char_22_cwe_bar1Global;
extern int CWE476_NULL_Pointer_Dereference__char_22_cwe_bar2Global;
extern int CWE476_NULL_Pointer_Dereference__char_22_cwe_fooGlobal;
extern int testset3_22b_barB2DBGlobal;


void CWE476_NULL_Pointer_Dereference__char_22_cwe_bar1Sink(char * data)
{
    if(CWE476_NULL_Pointer_Dereference__char_22_cwe_bar1Global)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        if (data != NULL)
        {
            
            printf("%02x\n", data[0]);
        }
        else
        {
            printLine("data is NULL");
        }
    }
}


void CWE476_NULL_Pointer_Dereference__char_22_cwe_bar2Sink(char * data)
{
    if(CWE476_NULL_Pointer_Dereference__char_22_cwe_bar2Global)
    {
        
        if (data != NULL)
        {
            
            printf("%02x\n", data[0]);
        }
        else
        {
            printLine("data is NULL");
        }
    }
}


void CWE476_NULL_Pointer_Dereference__char_22_cwe_fooSink(char * data)
{
    if(CWE476_NULL_Pointer_Dereference__char_22_cwe_fooGlobal)
    {
        
        
        printf("%02x\n", data[0]);
    }
}

void testset3_22b_barB2DBSink(char* data)
{
	if(testset3_22b_barB2DBGlobal)
	{
		
		printf("%02x\n", data[0]);
	}
}


