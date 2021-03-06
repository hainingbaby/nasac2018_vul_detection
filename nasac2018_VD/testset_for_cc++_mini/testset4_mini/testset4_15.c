
#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define SRC_STR "0123456789abcde0123"

typedef struct _charVoid
{
    char charFirst[16];
    void * voidSecond;
    void * voidThird;
} charVoid;



void testset4_15_foo()
{
    switch(6)
    {
    case 6:
    {
        charVoid * structCharVoid = (charVoid *)malloc(sizeof(charVoid));
        structCharVoid->voidSecond = (void *)SRC_STR;
        
        printLine((char *)structCharVoid->voidSecond);
        
        memcpy(structCharVoid->charFirst, SRC_STR, sizeof(*structCharVoid));
        structCharVoid->charFirst[(sizeof(structCharVoid->charFirst)/sizeof(char))-1] = '\0'; 
        printLine((char *)structCharVoid->charFirst);
        printLine((char *)structCharVoid->voidSecond);
        free(structCharVoid);
    }
    break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}






static void good1()
{
    switch(5)
    {
    case 6:
        
        printLine("Benign, fixed string");
        break;
    default:
    {
        charVoid * structCharVoid = (charVoid *)malloc(sizeof(charVoid));
        structCharVoid->voidSecond = (void *)SRC_STR;
        
        printLine((char *)structCharVoid->voidSecond);
        
        memcpy(structCharVoid->charFirst, SRC_STR, sizeof(structCharVoid->charFirst));
        structCharVoid->charFirst[(sizeof(structCharVoid->charFirst)/sizeof(char))-1] = '\0'; 
        printLine((char *)structCharVoid->charFirst);
        printLine((char *)structCharVoid->voidSecond);
        free(structCharVoid);
    }
    break;
    }
}


static void good2()
{
    switch(6)
    {
    case 6:
    {
        charVoid * structCharVoid = (charVoid *)malloc(sizeof(charVoid));
        structCharVoid->voidSecond = (void *)SRC_STR;
        
        printLine((char *)structCharVoid->voidSecond);
        
        memcpy(structCharVoid->charFirst, SRC_STR, sizeof(structCharVoid->charFirst));
        structCharVoid->charFirst[(sizeof(structCharVoid->charFirst)/sizeof(char))-1] = '\0'; 
        printLine((char *)structCharVoid->charFirst);
        printLine((char *)structCharVoid->voidSecond);
        free(structCharVoid);
    }
    break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
}

void testset4_15_bar()
{
    good1();
    good2();
}



