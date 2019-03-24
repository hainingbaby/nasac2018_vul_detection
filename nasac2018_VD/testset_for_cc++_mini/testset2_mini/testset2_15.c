
#include "std_testcase.h"

#include <wchar.h>



void testset2_15_foo()
{
    char * data;
    
    data = NULL;
    switch(6)
    {
    case 6:
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
        
        free(data);
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}






static void cwe_bar1()
{
    char * data;
    
    data = NULL;
    switch(6)
    {
    case 6:
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(8)
    {
    case 7:
        
        printLine("Benign, fixed string");
        break;
    default:
        
        
        ; 
        break;
    }
}


static void cwe_bar2()
{
    char * data;
    
    data = NULL;
    switch(6)
    {
    case 6:
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        free(data);
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
        
        
        ; 
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}


static void cwe_foo1()
{
    char * data;
    
    data = NULL;
    switch(5)
    {
    case 6:
        
        printLine("Benign, fixed string");
        break;
    default:
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        break;
    }
    switch(7)
    {
    case 7:
        
        free(data);
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}


static void cwe_foo2()
{
    char * data;
    
    data = NULL;
    switch(6)
    {
    case 6:
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
        
        free(data);
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}

void testset2_15_bar()
{
    cwe_bar1();
    cwe_bar2();
    cwe_foo1();
    cwe_foo2();
}



