
#include "std_testcase.h"

namespace testset1_82
{

class testset1_82_base
{
public:
    
    virtual void action(int data) = 0;
};



class testset1_82_foo_bar : public testset1_82_base
{
public:
    void action(int data);
};





class testset1_82_foo : public testset1_82_base
{
public:
    void action(int data);
};

class testset1_82_bar : public testset1_82_base
{
public:
    void action(int data);
};



}
