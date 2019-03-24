package testcases.testset4;

import testcasesupport.*;

public class testset4_3_45 extends AbstractTestCase
{
    private String dataBad;
    private String dataGoodG2B;
    private String dataGoodB2G;

    private void foo_barSink() throws Throwable
    {
        String data = dataBad;

        
        IO.writeLine("" + data.length());

    }

    public void foo_bar() throws Throwable
    {
        String data;

        
        data = null;

        dataBad = data;
        foo_barSink();
    }

    public void good() throws Throwable
    {
        cwe_foo();
        cwe_bar();
    }

    private void cwe_fooSink() throws Throwable
    {
        String data = dataGoodG2B;

        
        IO.writeLine("" + data.length());

    }

    
    private void cwe_foo() throws Throwable
    {
        String data;

        
        data = "This is not null";

        dataGoodG2B = data;
        cwe_fooSink();
    }

    private void cwe_barSink() throws Throwable
    {
        String data = dataGoodB2G;

        
        if (data != null)
        {
            IO.writeLine("" + data.length());
        }
        else
        {
            IO.writeLine("data is null");
        }

    }

    
    private void cwe_bar() throws Throwable
    {
        String data;

        
        data = null;

        dataGoodB2G = data;
        cwe_barSink();
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
