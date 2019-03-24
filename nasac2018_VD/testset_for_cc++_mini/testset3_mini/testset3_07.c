
#include "std_testcase.h"

#include <wchar.h>




static int staticFive = 5;



void testset3_07_foo()
{
    char * data;
    if(staticFive==5)
    {
        
        data = NULL;
    }
    if(staticFive==5)
    {
        
        
        printf("%02x\n", data[0]);
    }
}






static void cwe_bar1()
{
    char * data;
    if(staticFive==5)
    {
        
        data = NULL;
    }
    if(staticFive!=5)
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
    if(staticFive==5)
    {
        
        data = NULL;
    }
    if(staticFive==5)
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
    if(staticFive!=5)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = "Good";
    }
    if(staticFive==5)
    {
        
        
        printf("%02x\n", data[0]);
    }
}


static void cwe_foo2()
{
    char * data;
    if(staticFive==5)
    {
        
        data = "Good";
    }
    if(staticFive==5)
    {
        
        
        printf("%02x\n", data[0]);
    }
}

static void goodB2DB()
{
	char* data;
	data = NULL;
	if(staticFive!=5)
	{
		
		printf("%02x\n", data[0]);
	}
}

void testset3_07_bar()
{
    cwe_bar1();
    cwe_bar2();
    cwe_foo1();
    cwe_foo2();
    goodB2DB();
}



