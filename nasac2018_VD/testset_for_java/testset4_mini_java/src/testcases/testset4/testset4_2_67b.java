package testcases.testset4;

import testcasesupport.*;

public class testset4_2_67b
{
    public void foo_barSink(testset4_2_67a.Container dataContainer ) throws Throwable
    {
        int [] data = dataContainer.containerOne;

        
        IO.writeLine("" + data.length);

    }

    
    public void cwe_fooSink(testset4_2_67a.Container dataContainer ) throws Throwable
    {
        int [] data = dataContainer.containerOne;

        
        IO.writeLine("" + data.length);

    }

    
    public void cwe_barSink(testset4_2_67a.Container dataContainer ) throws Throwable
    {
        int [] data = dataContainer.containerOne;

        
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
