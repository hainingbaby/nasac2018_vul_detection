
#include "std_testcase.h"

#include <wchar.h>

namespace testset3_82
{

class testset3_82_base
{
public:
    
    virtual void action(char * data) = 0;
};



class testset3_82_foo_bar : public testset3_82_base
{
public:
    void action(char * data);
};





class testset3_82_foo : public testset3_82_base
{
public:
    void action(char * data);
};

class testset3_82_bar : public testset3_82_base
{
public:
    void action(char * data);
};



}
