
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



void testset4_18_foo()
{
    goto sink;
sink:
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
}






static void good1()
{
    goto sink;
sink:
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
}

void testset4_18_bar()
{
    good1();
}



