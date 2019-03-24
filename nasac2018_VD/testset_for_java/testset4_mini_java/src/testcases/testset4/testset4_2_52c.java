package testcases.testset4;

import testcasesupport.*;

public class testset4_2_52c
{
    public void foo_barSink(int [] data ) throws Throwable
    {

        
        IO.writeLine("" + data.length);

    }

    
    public void cwe_fooSink(int [] data ) throws Throwable
    {

        
        IO.writeLine("" + data.length);

    }

    
    public void cwe_barSink(int [] data ) throws Throwable
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
