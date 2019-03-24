
#include "std_testcase.h"

#include <wchar.h>



void testset2_11_foo()
{
    char * data;
    
    data = NULL;
    if(globalReturnsTrue())
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
    }
    if(globalReturnsTrue())
    {
        
        free(data);
    }
}






static void cwe_bar1()
{
    char * data;
    
    data = NULL;
    if(globalReturnsTrue())
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
    }
    if(globalReturnsFalse())
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
    if(globalReturnsTrue())
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
    }
    if(globalReturnsTrue())
    {
        
        
        ; 
    }
}


static void cwe_foo1()
{
    char * data;
    
    data = NULL;
    if(globalReturnsFalse())
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
    }
    if(globalReturnsTrue())
    {
        
        free(data);
    }
}


static void cwe_foo2()
{
    char * data;
    
    data = NULL;
    if(globalReturnsTrue())
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
    }
    if(globalReturnsTrue())
    {
        
        free(data);
    }
}

void testset2_11_bar()
{
    cwe_bar1();
    cwe_bar2();
    cwe_foo1();
    cwe_foo2();
}



