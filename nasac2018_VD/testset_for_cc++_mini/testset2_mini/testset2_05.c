
#include "std_testcase.h"

#include <wchar.h>




static int staticTrue = 1; 
static int staticFalse = 0; 



void testset2_05_foo()
{
    char * data;
    
    data = NULL;
    if(staticTrue)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
    }
    if(staticTrue)
    {
        
        free(data);
    }
}






static void cwe_bar1()
{
    char * data;
    
    data = NULL;
    if(staticTrue)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
    }
    if(staticFalse)
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
    if(staticTrue)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
    }
    if(staticTrue)
    {
        
        
        ; 
    }
}


static void cwe_foo1()
{
    char * data;
    
    data = NULL;
    if(staticFalse)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
    }
    if(staticTrue)
    {
        
        free(data);
    }
}


static void cwe_foo2()
{
    char * data;
    
    data = NULL;
    if(staticTrue)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
    }
    if(staticTrue)
    {
        
        free(data);
    }
}

void testset2_05_bar()
{
    cwe_bar1();
    cwe_bar2();
    cwe_foo1();
    cwe_foo2();
}



