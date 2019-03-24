
#include "std_testcase.h"

#include <wchar.h>

namespace testset2_82
{

class testset2_82_base
{
public:
    
    virtual void action(char * data) = 0;
};



class testset2_82_foo_bar : public testset2_82_base
{
public:
    void action(char * data);
};





class testset2_82_foo : public testset2_82_base
{
public:
    void action(char * data);
};

class testset2_82_bar : public testset2_82_base
{
public:
    void action(char * data);
};



}
