
#include "std_testcase.h"

#include <wchar.h>




static int badStatic = 0;

static void badSink(char * data)
{
    if(badStatic)
    {
        
        
        printf("%02x\n", data[0]);
    }
}

void testset3_21_foo()
{
    char * data;
    
    data = NULL;
    badStatic = 1; 
    badSink(data);
}






static int cwe_bar1Static = 0;
static int cwe_bar2Static = 0;
static int cwe_fooStatic = 0;
static int goodB2DBStatic = 0;


static void cwe_bar1Sink(char * data)
{
    if(cwe_bar1Static)
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

static void cwe_bar1()
{
    char * data;
    
    data = NULL;
    cwe_bar1Static = 0; 
    cwe_bar1Sink(data);
}


static void cwe_bar2Sink(char * data)
{
    if(cwe_bar2Static)
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
    
    data = NULL;
    cwe_bar2Static = 1; 
    cwe_bar2Sink(data);
}


static void cwe_fooSink(char * data)
{
    if(cwe_fooStatic)
    {
        
        
        printf("%02x\n", data[0]);
    }
}

static void cwe_foo()
{
    char * data;
    
    data = "Good";
    cwe_fooStatic = 1; 
    cwe_fooSink(data);
}


static void goodB2DBSink(char * data)
{
    if(goodB2DBStatic)
    {
        
        printf("%02x\n", data[0]);
    }
}

static void goodB2DB()
{
    char * data;
    
    data = NULL;
    goodB2DBStatic = 0; 
    goodB2DBSink(data);
}

void testset3_21_bar()
{
    cwe_bar1();
    cwe_bar2();
    cwe_foo();
    goodB2DB();
}



