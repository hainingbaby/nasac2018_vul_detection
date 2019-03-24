
#include "std_testcase.h"

#include <wchar.h>

namespace testset2_81
{

class testset2_81_base
{
public:
    
    virtual void action(char * data) const = 0;
};



class testset2_81_foo_bar : public testset2_81_base
{
public:
    void action(char * data) const;
};





class testset2_81_foo : public testset2_81_base
{
public:
    void action(char * data) const;
};

class testset2_81_bar : public testset2_81_base
{
public:
    void action(char * data) const;
};



}
