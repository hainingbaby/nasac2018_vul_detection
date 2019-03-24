package testcases.testset4;

import testcasesupport.*;

public class testset4_2_71b
{
    public void foo_barSink(Object dataObject ) throws Throwable
    {
        int [] data = (int [])dataObject;

        
        IO.writeLine("" + data.length);

    }

    
    public void cwe_fooSink(Object dataObject ) throws Throwable
    {
        int [] data = (int [])dataObject;

        
        IO.writeLine("" + data.length);

    }

    
    public void cwe_barSink(Object dataObject ) throws Throwable
    {
        int [] data = (int [])dataObject;

        
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
