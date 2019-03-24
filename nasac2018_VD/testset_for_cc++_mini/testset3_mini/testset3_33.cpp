
#include "std_testcase.h"

#include <wchar.h>

namespace testset3_33
{



void foo_bar()
{
    char * data;
    char * &dataRef = data;
    
    data = NULL;
    {
        char * data = dataRef;
        
        
        printf("%02x\n", data[0]);
    }
}






static void cwe_foo()
{
    char * data;
    char * &dataRef = data;
    
    data = "Good";
    {
        char * data = dataRef;
        
        
        printf("%02x\n", data[0]);
    }
}


static void cwe_bar()
{
    char * data;
    char * &dataRef = data;
    
    data = NULL;
    {
        char * data = dataRef;
        
        if (data != NULL)
        {
            
            printf("%02x\n", data[0]);
        }
        else
        {
            printLine("data is NULL");
        }
    }
}

void good()
{
    cwe_foo();
    cwe_bar();
}



} 

