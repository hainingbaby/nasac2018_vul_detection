
#include "std_testcase.h"

#include <wchar.h>

static char * testset3_45_fooData;
static char * CWE476_NULL_Pointer_Dereference__char_45_cwe_fooData;
static char * CWE476_NULL_Pointer_Dereference__char_45_cwe_barData;



static void badSink()
{
    char * data = testset3_45_fooData;
    
    
    printf("%02x\n", data[0]);
}

void testset3_45_foo()
{
    char * data;
    
    data = NULL;
    testset3_45_fooData = data;
    badSink();
}






static void cwe_fooSink()
{
    char * data = CWE476_NULL_Pointer_Dereference__char_45_cwe_fooData;
    
    
    printf("%02x\n", data[0]);
}

static void cwe_foo()
{
    char * data;
    
    data = "Good";
    CWE476_NULL_Pointer_Dereference__char_45_cwe_fooData = data;
    cwe_fooSink();
}


static void cwe_barSink()
{
    char * data = CWE476_NULL_Pointer_Dereference__char_45_cwe_barData;
    
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
    CWE476_NULL_Pointer_Dereference__char_45_cwe_barData = data;
    cwe_barSink();
}

void testset3_45_bar()
{
    cwe_foo();
    cwe_bar();
}



