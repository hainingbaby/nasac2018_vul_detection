
#include "std_testcase.h"

#include <wchar.h>

namespace testset2_33
{



void foo_bar()
{
    char * data;
    char * &dataRef = data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    {
        char * data = dataRef;
        
        free(data);
    }
}






static void cwe_foo()
{
    char * data;
    char * &dataRef = data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    {
        char * data = dataRef;
        
        free(data);
    }
}


static void cwe_bar()
{
    char * data;
    char * &dataRef = data;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    {
        char * data = dataRef;
        
        
        ; 
    }
}

void good()
{
    cwe_foo();
    cwe_bar();
}



} 

