
#include "std_testcase.h"
#include "testset2_83.h"

namespace testset2_83
{
testset2_83_foo::testset2_83_foo(char * dataCopy)
{
    data = dataCopy;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    
}

testset2_83_foo::~testset2_83_foo()
{
    
    free(data);
}
}

