
#include "std_testcase.h"

#include <wchar.h>



void CWE476_NULL_Pointer_Dereference__char_10_bad()
{
    char * data;
    if(globalTrue)
    {
        
        data = NULL;
    }
    if(globalTrue)
    {
        
        
        printf("%02x\n", data[0]);
    }
}






static void cwe_bar1()
{
    char * data;
    if(globalTrue)
    {
        
        data = NULL;
    }
    if(globalFalse)
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


static void cwe_bar2()
{
    char * data;
    if(globalTrue)
    {
        
        data = NULL;
    }
    if(globalTrue)
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


static void cwe_foo1()
{
    char * data;
    if(globalFalse)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = "Good";
    }
    if(globalTrue)
    {
        
        
        printf("%02x\n", data[0]);
    }
}


static void cwe_foo2()
{
    char * data;
    if(globalTrue)
    {
        
        data = "Good";
    }
    if(globalTrue)
    {
        
        
        printf("%02x\n", data[0]);
    }
}

static void goodB2DB()
{
	char* data;
	data = NULL;
	if(globalFalse)
	{
		
		printf("%02x\n", data[0]);
	}
}

void CWE476_NULL_Pointer_Dereference__char_10_good()
{
    cwe_bar1();
    cwe_bar2();
    cwe_foo1();
    cwe_foo2();
    goodB2DB();
}



