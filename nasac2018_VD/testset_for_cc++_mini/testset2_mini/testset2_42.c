
#include "std_testcase.h"

#include <wchar.h>



static char * badSource(char * data)
{
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    return data;
}

void testset2_42_foo()
{
    char * data;
    
    data = NULL;
    data = badSource(data);
    
    free(data);
}






static char * cwe_fooSource(char * data)
{
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    return data;
}

static void cwe_foo()
{
    char * data;
    
    data = NULL;
    data = cwe_fooSource(data);
    
    free(data);
}


static char * cwe_barSource(char * data)
{
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    return data;
}

static void cwe_bar()
{
    char * data;
    
    data = NULL;
    data = cwe_barSource(data);
    
    
    ; 
}

void testset2_42_bar()
{
    cwe_bar();
    cwe_foo();
}



