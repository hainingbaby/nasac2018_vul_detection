
#include "std_testcase.h"

#include <wchar.h>



void testset2_16_foo()
{
    char * data;
    
    data = NULL;
    while(1)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
        break;
    }
    while(1)
    {
        
        free(data);
        break;
    }
}






static void cwe_bar()
{
    char * data;
    
    data = NULL;
    while(1)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
        break;
    }
    while(1)
    {
        
        
        ; 
        break;
    }
}


static void cwe_foo()
{
    char * data;
    
    data = NULL;
    while(1)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        break;
    }
    while(1)
    {
        
        free(data);
        break;
    }
}

void testset2_16_bar()
{
    cwe_bar();
    cwe_foo();
}



