
#include "std_testcase.h"

#include <wchar.h>



static void badSink(char * data)
{
    
    
    printf("%02x\n", data[0]);
}

void testset3_44_foo()
{
    char * data;
    
    void (*funcPtr) (char *) = badSink;
    
    data = NULL;
    
    funcPtr(data);
}






static void cwe_fooSink(char * data)
{
    
    
    printf("%02x\n", data[0]);
}

static void cwe_foo()
{
    char * data;
    void (*funcPtr) (char *) = cwe_fooSink;
    
    data = "Good";
    funcPtr(data);
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
    void (*funcPtr) (char *) = cwe_barSink;
    
    data = NULL;
    funcPtr(data);
}

void testset3_44_bar()
{
    cwe_foo();
    cwe_bar();
}



