
#include "std_testcase.h"

#include <wchar.h>




static int badStatic = 0;

static void badSink(char * data)
{
    if(badStatic)
    {
        
        free(data);
    }
}

void testset2_21_foo()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    badStatic = 1; 
    badSink(data);
}






static int cwe_bar1Static = 0;
static int cwe_bar2Static = 0;
static int cwe_fooStatic = 0;


static void cwe_bar1Sink(char * data)
{
    if(cwe_bar1Static)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        
        ; 
    }
}

static void cwe_bar1()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    cwe_bar1Static = 0; 
    cwe_bar1Sink(data);
}


static void cwe_bar2Sink(char * data)
{
    if(cwe_bar2Static)
    {
        
        
        ; 
    }
}

static void cwe_bar2()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    cwe_bar2Static = 1; 
    cwe_bar2Sink(data);
}


static void cwe_fooSink(char * data)
{
    if(cwe_fooStatic)
    {
        
        free(data);
    }
}

static void cwe_foo()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    cwe_fooStatic = 1; 
    cwe_fooSink(data);
}

void testset2_21_bar()
{
    cwe_bar1();
    cwe_bar2();
    cwe_foo();
}



