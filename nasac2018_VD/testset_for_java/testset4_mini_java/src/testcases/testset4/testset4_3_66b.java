package testcases.testset4;

import testcasesupport.*;

public class testset4_3_66b
{
    public void foo_barSink(String dataArray[] ) throws Throwable
    {
        String data = dataArray[2];

        
        IO.writeLine("" + data.length());

    }

    
    public void cwe_fooSink(String dataArray[] ) throws Throwable
    {
        String data = dataArray[2];

        
        IO.writeLine("" + data.length());

    }

    
    public void cwe_barSink(String dataArray[] ) throws Throwable
    {
        String data = dataArray[2];

        
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
