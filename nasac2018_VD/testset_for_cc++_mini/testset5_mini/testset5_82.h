
#include "std_testcase.h"

namespace testset5_82
{

class testset5_82_base
{
public:
    
    virtual void action(int * data) = 0;
};



class testset5_82_foo_bar : public testset5_82_base
{
public:
    void action(int * data);
};





class testset5_82_foo : public testset5_82_base
{
public:
    void action(int * data);
};



}
