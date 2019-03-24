
#include "std_testcase.h"
#include "testset2_84.h"

namespace testset2_84
{
testset2_84_foo::testset2_84_foo(char * dataCopy)
{
    data = dataCopy;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
}

testset2_84_foo::~testset2_84_foo()
{
    
    free(data);
}
}

