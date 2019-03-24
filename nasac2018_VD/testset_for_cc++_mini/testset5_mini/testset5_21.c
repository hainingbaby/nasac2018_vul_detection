
#include "std_testcase.h"




static int badStatic = 0;

static int * badSource(int * data)
{
    if(badStatic)
    {
        
        data = (int *)malloc(10);
    }
    return data;
}

void testset5_21_foo()
{
    int * data;
    data = NULL;
    badStatic = 1; 
    data = badSource(data);
    {
        int source[10] = {0};
        size_t i;
        
        for (i = 0; i < 10; i++)
        {
            data[i] = source[i];
        }
        printIntLine(data[0]);
        free(data);
    }
}






static int cwe_foo1Static = 0;
static int cwe_foo2Static = 0;


static int * cwe_foo1Source(int * data)
{
    if(cwe_foo1Static)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = (int *)malloc(10*sizeof(int));
    }
    return data;
}

static void cwe_foo1()
{
    int * data;
    data = NULL;
    cwe_foo1Static = 0; 
    data = cwe_foo1Source(data);
    {
        int source[10] = {0};
        size_t i;
        
        for (i = 0; i < 10; i++)
        {
            data[i] = source[i];
        }
        printIntLine(data[0]);
        free(data);
    }
}


static int * cwe_foo2Source(int * data)
{
    if(cwe_foo2Static)
    {
        
        data = (int *)malloc(10*sizeof(int));
    }
    return data;
}

static void cwe_foo2()
{
    int * data;
    data = NULL;
    cwe_foo2Static = 1; 
    data = cwe_foo2Source(data);
    {
        int source[10] = {0};
        size_t i;
        
        for (i = 0; i < 10; i++)
        {
            data[i] = source[i];
        }
        printIntLine(data[0]);
        free(data);
    }
}

void testset5_21_bar()
{
    cwe_foo1();
    cwe_foo2();
}



