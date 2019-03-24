
#include "std_testcase.h"

#include <wchar.h>



void testset3_16_foo()
{
    char * data;
    while(1)
    {
        
        data = NULL;
        break;
    }
    while(1)
    {
        
        
        printf("%02x\n", data[0]);
        break;
    }
}






static void cwe_bar()
{
    char * data;
    while(1)
    {
        
        data = NULL;
        break;
    }
    while(1)
    {
        
        if (data != NULL)
        {
            
            printf("%02x\n", data[0]);
        }
        else
        {
            printLine("data is NULL");
        }
        break;
    }
}


static void cwe_foo()
{
    char * data;
    while(1)
    {
        
        data = "Good";
        break;
    }
    while(1)
    {
        
        
        printf("%02x\n", data[0]);
        break;
    }
}

static void goodB2DB()
{
	char* data;
	data = NULL;
	while(0)
	{
		
		printf("%02x\n", data[0]);
	}
}

void testset3_16_bar()
{
    cwe_bar();
    cwe_foo();
    goodB2DB();
}



