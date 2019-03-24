
#include "std_testcase.h"

#include <wchar.h>




static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}



void testset3_08_foo()
{
    char * data;
    if(staticReturnsTrue())
    {
        
        data = NULL;
    }
    if(staticReturnsTrue())
    {
        
        
        printf("%02x\n", data[0]);
    }
}






static void cwe_bar1()
{
    char * data;
    if(staticReturnsTrue())
    {
        
        data = NULL;
    }
    if(staticReturnsFalse())
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
    if(staticReturnsTrue())
    {
        
        data = NULL;
    }
    if(staticReturnsTrue())
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
    if(staticReturnsFalse())
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = "Good";
    }
    if(staticReturnsTrue())
    {
        
        
        printf("%02x\n", data[0]);
    }
}


static void cwe_foo2()
{
    char * data;
    if(staticReturnsTrue())
    {
        
        data = "Good";
    }
    if(staticReturnsTrue())
    {
        
        
        printf("%02x\n", data[0]);
    }
}

static void goodB2DB()
{
	char* data;
	data = NULL;
	if(staticReturnsFalse())
	{
		
		printf("%02x\n", data[0]);
	}
}

void testset3_08_bar()
{
    cwe_bar1();
    cwe_bar2();
    cwe_foo1();
    cwe_foo2();
    goodB2DB();
}



