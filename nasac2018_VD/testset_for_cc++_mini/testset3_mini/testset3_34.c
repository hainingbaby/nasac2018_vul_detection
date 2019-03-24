
#include "std_testcase.h"

#include <wchar.h>

typedef union
{
    char * unionFirst;
    char * unionSecond;
} CWE476_NULL_Pointer_Dereference__char_34_unionType;



void testset3_34_foo()
{
    char * data;
    CWE476_NULL_Pointer_Dereference__char_34_unionType myUnion;
    
    data = NULL;
    myUnion.unionFirst = data;
    {
        char * data = myUnion.unionSecond;
        
        
        printf("%02x\n", data[0]);
    }
}






static void cwe_foo()
{
    char * data;
    CWE476_NULL_Pointer_Dereference__char_34_unionType myUnion;
    
    data = "Good";
    myUnion.unionFirst = data;
    {
        char * data = myUnion.unionSecond;
        
        
        printf("%02x\n", data[0]);
    }
}


static void cwe_bar()
{
    char * data;
    CWE476_NULL_Pointer_Dereference__char_34_unionType myUnion;
    
    data = NULL;
    myUnion.unionFirst = data;
    {
        char * data = myUnion.unionSecond;
        
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

void testset3_34_bar()
{
    cwe_foo();
    cwe_bar();
}



