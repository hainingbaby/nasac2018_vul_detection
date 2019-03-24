
#include "std_testcase.h"

namespace testset5_62
{



void foo_barSource(int * &data)
{
    
    data = (int *)malloc(10);
}






void cwe_fooSource(int * &data)
{
    
    data = (int *)malloc(10*sizeof(int));
}



} 
