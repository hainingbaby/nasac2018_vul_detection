
#include "std_testcase.h"

#include <wchar.h>




static int staticTrue = 1; 
static int staticFalse = 0; 



void testset3_05_foo()
{
    char * data;
    if(staticTrue)
    {
        
        data = NULL;
    }
    if(staticTrue)
    {
        
        
        printf("%02x\n", data[0]);
    }
}






static void cwe_bar1()
{
    char * data;
    if(staticTrue)
    {
        
        data = NULL;
    }
    if(staticFalse)
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
    if(staticTrue)
    {
        
        data = NULL;
    }
    if(staticTrue)
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
    if(staticFalse)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = "Good";
    }
    if(staticTrue)
    {
        
        
        printf("%02x\n", data[0]);
    }
}


static void cwe_foo2()
{
    char * data;
    if(staticTrue)
    {
        
        data = "Good";
    }
    if(staticTrue)
    {
        
        
        printf("%02x\n", data[0]);
    }
}

static void goodB2DB()
{
	char* data;
	data = NULL;
	if(staticFalse)
	{
		
		printf("%02x\n", data[0]);
	}
}

void testset3_05_bar()
{
    cwe_bar1();
    cwe_bar2();
    cwe_foo1();
    cwe_foo2();
    goodB2DB();
}



