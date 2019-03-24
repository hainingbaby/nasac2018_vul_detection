
#include "std_testcase.h"

#include <wchar.h>


static int n0 = 0;
static int n1 = 1;
void testset3_17_foo()
{
    int i,j;
    char * data;
    for(i = 0; i < n1; i++)
    {
        
        data = NULL;
    }
    for(j = 0; j < n1; j++)
    {
        
        
        printf("%02x\n", data[0]);
    }
}






static void cwe_bar()
{
    int i,k;
    char * data;
    for(i = 0; i < n1; i++)
    {
        
        data = NULL;
    }
    for(k = 0; k < n1; k++)
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


static void cwe_foo()
{
    int h,j;
    char * data;
    for(h = 0; h < n1; h++)
    {
        
        data = "Good";
    }
    for(j = 0; j < n1; j++)
    {
        
        
        printf("%02x\n", data[0]);
    }
}

static void goodB2DB()
{
	char* data;
	data = NULL;
	int i;
	for(i=0; i<n0; i++)
	{
		
		printf("%02x\n", data[0]);
	}
}

void testset3_17_bar()
{
    cwe_bar();
    cwe_foo();
    goodB2DB();
}



