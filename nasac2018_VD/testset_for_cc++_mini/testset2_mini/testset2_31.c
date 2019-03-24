
#include "std_testcase.h"

#include <wchar.h>



void testset2_31_foo()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    {
        char * dataCopy = data;
        char * data = dataCopy;
        
        free(data);
    }
}






static void cwe_foo()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    {
        char * dataCopy = data;
        char * data = dataCopy;
        
        free(data);
    }
}


static void cwe_bar()
{
    char * data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    {
        char * dataCopy = data;
        char * data = dataCopy;
        
        
        ; 
    }
}

void testset2_31_bar()
{
    cwe_foo();
    cwe_bar();
}



