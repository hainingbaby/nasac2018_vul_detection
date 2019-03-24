
#include "std_testcase.h"

#include <wchar.h>



void testset3_18_foo()
{
    char * data;
    goto source;
source:
    
    data = NULL;
    goto sink;
sink:
    
    
    printf("%02x\n", data[0]);
}






static void cwe_bar()
{
    char * data;
    goto source;
source:
    
    data = NULL;
    goto sink;
sink:
    
    if (data != NULL)
    {
        
        printf("%02x\n", data[0]);
    }
    else
    {
        printLine("data is NULL");
    }
}


static void cwe_foo()
{
    char * data;
    goto source;
source:
    
    data = "Good";
    goto sink;
sink:
    
    
    printf("%02x\n", data[0]);
}

static void goodB2DB()
{
	char* data;
	data = NULL;
	goto realsink;
	deadsink:
	
	printf("%02x\n", data[0]);
	realsink:
	printLine("Benign");
}

void testset3_18_bar()
{
    cwe_bar();
    cwe_foo();
    goodB2DB();
}



