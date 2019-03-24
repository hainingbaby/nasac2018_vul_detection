
#include "std_testcase.h"

#include <wchar.h>



void testset3_31_foo()
{
    char * data;
    
    data = NULL;
    {
        char * dataCopy = data;
        char * data = dataCopy;
        
        
        printf("%02x\n", data[0]);
    }
}






static void cwe_foo()
{
    char * data;
    
    data = "Good";
    {
        char * dataCopy = data;
        char * data = dataCopy;
        
        
        printf("%02x\n", data[0]);
    }
}


static void cwe_bar()
{
    char * data;
    
    data = NULL;
    {
        char * dataCopy = data;
        char * data = dataCopy;
        
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

void testset3_31_bar()
{
    cwe_foo();
    cwe_bar();
}



