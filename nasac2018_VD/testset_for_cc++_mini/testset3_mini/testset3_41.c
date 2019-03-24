
#include "std_testcase.h"

#include <wchar.h>



static void badSink(char * data)
{
    
    
    printf("%02x\n", data[0]);
}

void testset3_41_foo()
{
    char * data;
    
    data = NULL;
    badSink(data);
}






static void cwe_fooSink(char * data)
{
    
    
    printf("%02x\n", data[0]);
}

static void cwe_foo()
{
    char * data;
    
    data = "Good";
    cwe_fooSink(data);
}


static void cwe_barSink(char * data)
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

static void cwe_bar()
{
    char * data;
    
    data = NULL;
    cwe_barSink(data);
}

void testset3_41_bar()
{
    cwe_bar();
    cwe_foo();
}



