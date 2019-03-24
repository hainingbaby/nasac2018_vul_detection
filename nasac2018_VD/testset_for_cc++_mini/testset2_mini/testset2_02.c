
#include "std_testcase.h"

#include <wchar.h>



void testset2_02_foo()
{
    char * data;
    
    data = NULL;
    if(1)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
    }
    if(1)
    {
        
        free(data);
    }
}






static void cwe_bar1()
{
    char * data;
    
    data = NULL;
    if(1)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
    }
    if(0)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        
        ; 
    }
}


static void cwe_bar2()
{
    char * data;
    
    data = NULL;
    if(1)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
    }
    if(1)
    {
        
        
        ; 
    }
}


static void cwe_foo1()
{
    char * data;
    
    data = NULL;
    if(0)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
    }
    if(1)
    {
        
        free(data);
    }
}


static void cwe_foo2()
{
    char * data;
    
    data = NULL;
    if(1)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
    }
    if(1)
    {
        
        free(data);
    }
}

void testset2_02_bar()
{
    cwe_bar1();
    cwe_bar2();
    cwe_foo1();
    cwe_foo2();
}



