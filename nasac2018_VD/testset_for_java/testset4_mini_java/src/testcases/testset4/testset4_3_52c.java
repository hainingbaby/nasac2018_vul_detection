package testcases.testset4;

import testcasesupport.*;

public class testset4_3_52c
{
    public void foo_barSink(String data ) throws Throwable
    {

        
        IO.writeLine("" + data.length());

    }

    
    public void cwe_fooSink(String data ) throws Throwable
    {

        
        IO.writeLine("" + data.length());

    }

    
    public void cwe_barSink(String data ) throws Throwable
    {

        
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
