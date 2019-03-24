package testcases.testset4;

import testcasesupport.*;

public class testset4_3_22b
{
    public void foo_barSink(String data ) throws Throwable
    {
        if (testset4_3_22a.foo_barPublicStatic)
        {
            
            IO.writeLine("" + data.length());
        }
        else
        {
            

            data = null;
        }
    }

    
    public void cwe_bar1Sink(String data ) throws Throwable
    {
        if (testset4_3_22a.cwe_bar1PublicStatic)
        {
            

            data = null;
        }
        else
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

    
    public void cwe_bar2Sink(String data ) throws Throwable
    {
        if (testset4_3_22a.cwe_bar2PublicStatic)
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
        else
        {
            

            data = null;
        }
    }

    
    public void cwe_fooSink(String data ) throws Throwable
    {
        if (testset4_3_22a.cwe_fooPublicStatic)
        {
            
            IO.writeLine("" + data.length());
        }
        else
        {
            

            data = null;
        }
    }
}
