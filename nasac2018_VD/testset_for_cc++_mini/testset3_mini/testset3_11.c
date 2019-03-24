
#include "std_testcase.h"

#include <wchar.h>



void testset3_11_foo()
{
    char * data;
    if(globalReturnsTrue())
    {
        
        data = NULL;
    }
    if(globalReturnsTrue())
    {
        
        
        printf("%02x\n", data[0]);
    }
}






static void cwe_bar1()
{
    char * data;
    if(globalReturnsTrue())
    {
        
        data = NULL;
    }
    if(globalReturnsFalse())
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
    if(globalReturnsTrue())
    {
        
        data = NULL;
    }
    if(globalReturnsTrue())
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
    if(globalReturnsFalse())
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = "Good";
    }
    if(globalReturnsTrue())
    {
        
        
        printf("%02x\n", data[0]);
    }
}


static void cwe_foo2()
{
    char * data;
    if(globalReturnsTrue())
    {
        
        data = "Good";
    }
    if(globalReturnsTrue())
    {
        
        
        printf("%02x\n", data[0]);
    }
}

static void goodB2DB()
{
	char* data;
	data = NULL;
	if(globalReturnsFalse())
	{
		
		printf("%02x\n", data[0]);
	}
}

void testset3_11_bar()
{
    cwe_bar1();
    cwe_bar2();
    cwe_foo1();
    cwe_foo2();
    goodB2DB();
}



