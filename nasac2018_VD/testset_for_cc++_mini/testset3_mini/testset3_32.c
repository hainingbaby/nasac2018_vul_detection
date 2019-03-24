
#include "std_testcase.h"

#include <wchar.h>



void testset3_32_foo()
{
    char * data;
    char * *dataPtr1 = &data;
    char * *dataPtr2 = &data;
    {
        char * data = *dataPtr1;
        
        data = NULL;
        *dataPtr1 = data;
    }
    {
        char * data = *dataPtr2;
        
        
        printf("%02x\n", data[0]);
    }
}






static void cwe_foo()
{
    char * data;
    char * *dataPtr1 = &data;
    char * *dataPtr2 = &data;
    {
        char * data = *dataPtr1;
        
        data = "Good";
        *dataPtr1 = data;
    }
    {
        char * data = *dataPtr2;
        
        
        printf("%02x\n", data[0]);
    }
}


static void cwe_bar()
{
    char * data;
    char * *dataPtr1 = &data;
    char * *dataPtr2 = &data;
    {
        char * data = *dataPtr1;
        
        data = NULL;
        *dataPtr1 = data;
    }
    {
        char * data = *dataPtr2;
        
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

void testset3_32_bar()
{
    cwe_foo();
    cwe_bar();
}



