
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




static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}



void testset4_08_foo()
{
    if(staticReturnsTrue())
    {
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
}






static void good1()
{
    if(staticReturnsFalse())
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
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
}


static void good2()
{
    if(staticReturnsTrue())
    {
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
}

void testset4_08_bar()
{
    good1();
    good2();
}



