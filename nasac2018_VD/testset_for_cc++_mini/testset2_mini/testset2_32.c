
#include "std_testcase.h"

#include <wchar.h>



void testset2_32_foo()
{
    char * data;
    char * *dataPtr1 = &data;
    char * *dataPtr2 = &data;
    
    data = NULL;
    {
        char * data = *dataPtr1;
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
        *dataPtr1 = data;
    }
    {
        char * data = *dataPtr2;
        
        free(data);
    }
}






static void cwe_foo()
{
    char * data;
    char * *dataPtr1 = &data;
    char * *dataPtr2 = &data;
    
    data = NULL;
    {
        char * data = *dataPtr1;
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        *dataPtr1 = data;
    }
    {
        char * data = *dataPtr2;
        
        free(data);
    }
}


static void cwe_bar()
{
    char * data;
    char * *dataPtr1 = &data;
    char * *dataPtr2 = &data;
    
    data = NULL;
    {
        char * data = *dataPtr1;
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
        *dataPtr1 = data;
    }
    {
        char * data = *dataPtr2;
        
        
        ; 
    }
}

void testset2_32_bar()
{
    cwe_foo();
    cwe_bar();
}



