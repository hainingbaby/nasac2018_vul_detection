
#include "std_testcase.h"

#include <wchar.h>



void testset2_13_foo()
{
    char * data;
    
    data = NULL;
    if(GLOBAL_CONST_FIVE==5)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        
        free(data);
    }
}






static void cwe_bar1()
{
    char * data;
    
    data = NULL;
    if(GLOBAL_CONST_FIVE==5)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
    }
    if(GLOBAL_CONST_FIVE!=5)
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
    if(GLOBAL_CONST_FIVE==5)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        
        
        ; 
    }
}


static void cwe_foo1()
{
    char * data;
    
    data = NULL;
    if(GLOBAL_CONST_FIVE!=5)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        
        free(data);
    }
}


static void cwe_foo2()
{
    char * data;
    
    data = NULL;
    if(GLOBAL_CONST_FIVE==5)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        
        free(data);
    }
}

void testset2_13_bar()
{
    cwe_bar1();
    cwe_bar2();
    cwe_foo1();
    cwe_foo2();
}



