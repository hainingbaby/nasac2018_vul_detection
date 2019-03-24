
#include "std_testcase.h"

#include <wchar.h>

namespace testset2_62
{



void foo_barSource(char * &data)
{
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
}






void cwe_fooSource(char * &data)
{
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
}


void cwe_barSource(char * &data)
{
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
}



} 
