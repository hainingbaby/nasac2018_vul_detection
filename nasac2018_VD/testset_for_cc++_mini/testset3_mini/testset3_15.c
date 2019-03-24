
#include "std_testcase.h"

#include <wchar.h>


static int index5 = 5;
static int index6 = 6;
static int index7 = 7;
static int index8 = 8;
void testset3_15_foo()
{
    char * data;
    switch(index6)
    {
    case 6:
        
        data = NULL;
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(index7)
    {
    case 7:
        
        
        printf("%02x\n", data[0]);
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}






static void cwe_bar1()
{
    char * data;
    switch(index6)
    {
    case 6:
        
        data = NULL;
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(index8)
    {
    case 7:
        
        printLine("Benign, fixed string");
        break;
    default:
        
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


static void cwe_bar2()
{
    char * data;
    switch(index6)
    {
    case 6:
        
        data = NULL;
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(index7)
    {
    case 7:
        
        if (data != NULL)
        {
            
            printf("%02x\n", data[0]);
        }
        else
        {
            printLine("data is NULL");
        }
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}


static void cwe_foo1()
{
    char * data;
    switch(index5)
    {
    case 6:
        
        printLine("Benign, fixed string");
        break;
    default:
        
        data = "Good";
        break;
    }
    switch(index7)
    {
    case 7:
        
        
        printf("%02x\n", data[0]);
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}


static void cwe_foo2()
{
    char * data;
    switch(index6)
    {
    case 6:
        
        data = "Good";
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(index7)
    {
    case 7:
        
        
        printf("%02x\n", data[0]);
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}

static void goodB2DB()
{
	char* data;
	data = NULL;
	switch(index6)
	{
		case 7:
		
		printf("%02x\n", data[0]);
		break;
		default:
		printLine("Benign");
	}
}

void testset3_15_bar()
{
    cwe_bar1();
    cwe_bar2();
    cwe_foo1();
    cwe_foo2();
    goodB2DB();
}



