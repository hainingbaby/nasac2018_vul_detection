
#include "std_testcase.h"

namespace testset5_81
{

class testset5_81_base
{
public:
    
    virtual void action(int * data) const = 0;
};



class testset5_81_foo_bar : public testset5_81_base
{
public:
    void action(int * data) const;
};





class testset5_81_foo : public testset5_81_base
{
public:
    void action(int * data) const;
};



}
