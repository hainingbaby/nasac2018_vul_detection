package testcases.testset4;

import testcasesupport.*;

public class testset4_2_81_cwe_bar extends testset4_2_81_base
{
    public void action(int [] data ) throws Throwable
    {

        
        if (data != null)
        {
            IO.writeLine("" + data.length);
        }
        else
        {
            IO.writeLine("data is null");
        }

    }
}
