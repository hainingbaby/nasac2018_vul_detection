package testcases.testset4;

import testcasesupport.*;

public class testset4_3_71b
{
    public void foo_barSink(Object dataObject ) throws Throwable
    {
        String data = (String)dataObject;

        
        IO.writeLine("" + data.length());

    }

    
    public void cwe_fooSink(Object dataObject ) throws Throwable
    {
        String data = (String)dataObject;

        
        IO.writeLine("" + data.length());

    }

    
    public void cwe_barSink(Object dataObject ) throws Throwable
    {
        String data = (String)dataObject;

        
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
