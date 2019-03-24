
#include "std_testcase.h"

#include <wchar.h>

namespace testset3_81
{

class testset3_81_base
{
public:
    
    virtual void action(char * data) const = 0;
};



class testset3_81_foo_bar : public testset3_81_base
{
public:
    void action(char * data) const;
};





class testset3_81_foo : public testset3_81_base
{
public:
    void action(char * data) const;
};

class testset3_81_bar : public testset3_81_base
{
public:
    void action(char * data) const;
};



}
