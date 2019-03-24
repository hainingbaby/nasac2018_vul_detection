
#include "std_testcase.h"

#include <wchar.h>



void testset2_18_foo()
{
    char * data;
    
    data = NULL;
    goto source;
source:
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    goto sink;
sink:
    
    free(data);
}






static void cwe_bar()
{
    char * data;
    
    data = NULL;
    goto source;
source:
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    goto sink;
sink:
    
    
    ; 
}


static void cwe_foo()
{
    char * data;
    
    data = NULL;
    goto source;
source:
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    goto sink;
sink:
    
    free(data);
}

void testset2_18_bar()
{
    cwe_bar();
    cwe_foo();
}



