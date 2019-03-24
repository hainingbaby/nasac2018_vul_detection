package testcases.testset4;

import testcasesupport.*;

public class testset4_2_41 extends AbstractTestCase
{
    private void foo_barSink(int [] data ) throws Throwable
    {

        
        IO.writeLine("" + data.length);

    }

    public void foo_bar() throws Throwable
    {
        int [] data;

        
        data = null;

        foo_barSink(data  );
    }

    public void good() throws Throwable
    {
        cwe_foo();
        cwe_bar();
    }

    private void cwe_fooSink(int [] data ) throws Throwable
    {

        
        IO.writeLine("" + data.length);

    }

    
    private void cwe_foo() throws Throwable
    {
        int [] data;

        
        data = new int[5];

        cwe_fooSink(data  );
    }

    private void cwe_barSink(int [] data ) throws Throwable
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

    
    private void cwe_bar() throws Throwable
    {
        int [] data;

        
        data = null;

        cwe_barSink(data  );
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
