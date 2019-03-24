package testcases.testset4;

import testcasesupport.*;

public class testset4_3_67b
{
    public void foo_barSink(testset4_3_67a.Container dataContainer ) throws Throwable
    {
        String data = dataContainer.containerOne;

        
        IO.writeLine("" + data.length());

    }

    
    public void cwe_fooSink(testset4_3_67a.Container dataContainer ) throws Throwable
    {
        String data = dataContainer.containerOne;

        
        IO.writeLine("" + data.length());

    }

    
    public void cwe_barSink(testset4_3_67a.Container dataContainer ) throws Throwable
    {
        String data = dataContainer.containerOne;

        
        if (data != null)
        {
            IO.writeLine("" + data.length());
        }
        else
        {
            IO.writeLine("data is null");
        }

    }
}
