package testcases.testset4;

import testcasesupport.*;

public class testset4_2_68b
{
    public void foo_barSink() throws Throwable
    {
        int [] data = testset4_2_68a.data;

        
        IO.writeLine("" + data.length);

    }

    
    public void cwe_fooSink() throws Throwable
    {
        int [] data = testset4_2_68a.data;

        
        IO.writeLine("" + data.length);

    }

    
    public void cwe_barSink() throws Throwable
    {
        int [] data = testset4_2_68a.data;

        
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
