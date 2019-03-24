
#include "std_testcase.h"

#include <wchar.h>



void testset2_17_foo()
{
    int i,j;
    char * data;
    
    data = NULL;
    for(i = 0; i < 1; i++)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
    }
    for(j = 0; j < 1; j++)
    {
        
        free(data);
    }
}






static void cwe_bar()
{
    int i,k;
    char * data;
    
    data = NULL;
    for(i = 0; i < 1; i++)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
    }
    for(k = 0; k < 1; k++)
    {
        
        
        ; 
    }
}


static void cwe_foo()
{
    int h,j;
    char * data;
    
    data = NULL;
    for(h = 0; h < 1; h++)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
    }
    for(j = 0; j < 1; j++)
    {
        
        free(data);
    }
}

void testset2_17_bar()
{
    cwe_bar();
    cwe_foo();
}



