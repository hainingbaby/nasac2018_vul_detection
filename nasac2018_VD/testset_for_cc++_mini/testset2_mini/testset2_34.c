
#include "std_testcase.h"

#include <wchar.h>

typedef union
{
    char * unionFirst;
    char * unionSecond;
} CWE415_Double_Free__malloc_free_char_34_unionType;



void testset2_34_foo()
{
    char * data;
    CWE415_Double_Free__malloc_free_char_34_unionType myUnion;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    myUnion.unionFirst = data;
    {
        char * data = myUnion.unionSecond;
        
        free(data);
    }
}






static void cwe_foo()
{
    char * data;
    CWE415_Double_Free__malloc_free_char_34_unionType myUnion;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    myUnion.unionFirst = data;
    {
        char * data = myUnion.unionSecond;
        
        free(data);
    }
}


static void cwe_bar()
{
    char * data;
    CWE415_Double_Free__malloc_free_char_34_unionType myUnion;
    
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
    myUnion.unionFirst = data;
    {
        char * data = myUnion.unionSecond;
        
        
        ; 
    }
}

void testset2_34_bar()
{
    cwe_foo();
    cwe_bar();
}



