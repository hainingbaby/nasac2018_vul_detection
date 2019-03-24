
#include "std_testcase.h"

#include <wchar.h>



void testset2_12_foo()
{
    char * data;
    
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
    }
    else
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
    }
    if(globalReturnsTrueOrFalse())
    {
        
        free(data);
    }
    else
    {
        
        
        ; 
    }
}








static void cwe_bar()
{
    char * data;
    
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
    }
    else
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
    }
    if(globalReturnsTrueOrFalse())
    {
        
        
        ; 
    }
    else
    {
        
        
        ; 
    }
}




static void cwe_foo()
{
    char * data;
    
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
    }
    else
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
    }
    if(globalReturnsTrueOrFalse())
    {
        
        free(data);
    }
    else
    {
        
        free(data);
    }
}

void testset2_12_bar()
{
    cwe_bar();
    cwe_foo();
}



