
#include "std_testcase.h"

typedef union
{
    int * unionFirst;
    int * unionSecond;
} CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_34_unionType;



void testset5_34_foo()
{
    int * data;
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_34_unionType myUnion;
    data = NULL;
    
    data = (int *)malloc(10);
    myUnion.unionFirst = data;
    {
        int * data = myUnion.unionSecond;
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
}






static void cwe_foo()
{
    int * data;
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_34_unionType myUnion;
    data = NULL;
    
    data = (int *)malloc(10*sizeof(int));
    myUnion.unionFirst = data;
    {
        int * data = myUnion.unionSecond;
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
}

void testset5_34_bar()
{
    cwe_foo();
}



