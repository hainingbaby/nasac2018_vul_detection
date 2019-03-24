
#include "std_testcase.h"

#include <wchar.h>




void testset3_01_foo()
{
    char * data;
    
    data = NULL;
    
    
    printf("%02x\n", data[0]);
}






static void cwe_foo()
{
    char * data;
    
    data = "Good";
    
    
    printf("%02x\n", data[0]);
}


static void cwe_bar()
{
    char * data;
    
    data = NULL;
    
    if (data != NULL)
    {
        
        printf("%02x\n", data[0]);
    }
    else
    {
        printLine("data is NULL");
    }
}

void testset3_01_bar()
{
    cwe_foo();
    cwe_bar();
}



