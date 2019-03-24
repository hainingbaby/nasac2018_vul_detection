package testcases.testset4;

import testcasesupport.*;

public class testset4_3_68b
{
    public void foo_barSink() throws Throwable
    {
        String data = testset4_3_68a.data;

        
        IO.writeLine("" + data.length());

    }

    
    public void cwe_fooSink() throws Throwable
    {
        String data = testset4_3_68a.data;

        
        IO.writeLine("" + data.length());

    }

    
    public void cwe_barSink() throws Throwable
    {
        String data = testset4_3_68a.data;

        
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
