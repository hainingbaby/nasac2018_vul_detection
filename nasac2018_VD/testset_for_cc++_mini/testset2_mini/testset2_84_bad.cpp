
#include "std_testcase.h"
#include "testset2_84.h"

namespace testset2_84
{
testset2_84_foo_bar::testset2_84_foo_bar(char * dataCopy)
{
    data = dataCopy;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
    free(data);
}

testset2_84_foo_bar::~testset2_84_foo_bar()
{
    
    free(data);
}
}

