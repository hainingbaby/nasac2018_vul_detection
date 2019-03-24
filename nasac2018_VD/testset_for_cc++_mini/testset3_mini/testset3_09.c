
#include "std_testcase.h"

#include <wchar.h>



void testset3_09_foo()
{
    char * data;
    if(GLOBAL_CONST_TRUE)
    {
        
        data = NULL;
    }
    if(GLOBAL_CONST_TRUE)
    {
        
        
        printf("%02x\n", data[0]);
    }
}






static void cwe_bar1()
{
    char * data;
    if(GLOBAL_CONST_TRUE)
    {
        
        data = NULL;
    }
    if(GLOBAL_CONST_FALSE)
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
    if(GLOBAL_CONST_TRUE)
    {
        
        data = NULL;
    }
    if(GLOBAL_CONST_TRUE)
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
    if(GLOBAL_CONST_FALSE)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = "Good";
    }
    if(GLOBAL_CONST_TRUE)
    {
        
        
        printf("%02x\n", data[0]);
    }
}


static void cwe_foo2()
{
    char * data;
    if(GLOBAL_CONST_TRUE)
    {
        
        data = "Good";
    }
    if(GLOBAL_CONST_TRUE)
    {
        
        
        printf("%02x\n", data[0]);
    }
}

static void goodB2DB()
{
	char* data;
	data = NULL;
	if(GLOBAL_CONST_FALSE)
	{
		
		printf("%02x\n", data[0]);
	}
}

void testset3_09_bar()
{
    cwe_bar1();
    cwe_bar2();
    cwe_foo1();
    cwe_foo2();
    goodB2DB();
}



