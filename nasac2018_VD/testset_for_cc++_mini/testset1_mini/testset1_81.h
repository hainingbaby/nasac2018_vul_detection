
#include "std_testcase.h"

namespace testset1_81
{

class testset1_81_base
{
public:
    
    virtual void action(int data) const = 0;
};



class testset1_81_foo_bar : public testset1_81_base
{
public:
    void action(int data) const;
};





class testset1_81_foo : public testset1_81_base
{
public:
    void action(int data) const;
};

class testset1_81_bar : public testset1_81_base
{
public:
    void action(int data) const;
};



}
