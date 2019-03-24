
#include "std_testcase.h"

#include <wchar.h>



void testset3_12_foo()
{
    char * data;
    if(globalReturnsTrueOrFalse())
    {
        
        data = NULL;
    }
    else
    {
        
        data = "Good";
    }
    if(globalReturnsTrueOrFalse())
    {
        
        
        printf("%02x\n", data[0]);
    }
    else
    {
        
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








static void cwe_bar()
{
    char * data;
    if(globalReturnsTrueOrFalse())
    {
        
        data = NULL;
    }
    else
    {
        
        data = NULL;
    }
    if(globalReturnsTrueOrFalse())
    {
        
        if (data != NULL)
        {
            
            printf("%02x\n", data[0]);
        }
        else
        {
            printLine("data is NULL");
        }
    }
    else
    {
        
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




static void cwe_foo()
{
    char * data;
    if(globalReturnsTrueOrFalse())
    {
        
        data = "Good";
    }
    else
    {
        
        data = "Good";
    }
    if(globalReturnsTrueOrFalse())
    {
        
        
        printf("%02x\n", data[0]);
    }
    else
    {
        
        
        printf("%02x\n", data[0]);
    }
}

void testset3_12_bar()
{
    cwe_bar();
    cwe_foo();
}



