
#include "std_testcase.h"
#include "testset2_83.h"

namespace testset2_83
{
testset2_83_bar::testset2_83_bar(char * dataCopy)
{
    data = dataCopy;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
}

testset2_83_bar::~testset2_83_bar()
{
    
    
    ; 
}
}

