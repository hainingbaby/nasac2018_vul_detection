package testcases.testset4;

import testcasesupport.*;

public class testset4_2_42 extends AbstractTestCase
{
    private int [] foo_barSource() throws Throwable
    {
        int [] data;

        
        data = null;

        return data;
    }

    public void foo_bar() throws Throwable
    {
        int [] data = foo_barSource();

        
        IO.writeLine("" + data.length);

    }

    
    private int [] cwe_fooSource() throws Throwable
    {
        int [] data;

        
        data = new int[5];

        return data;
    }

    private void cwe_foo() throws Throwable
    {
        int [] data = cwe_fooSource();

        
        IO.writeLine("" + data.length);

    }

    
    private int [] cwe_barSource() throws Throwable
    {
        int [] data;

        
        data = null;

        return data;
    }

    private void cwe_bar() throws Throwable
    {
        int [] data = cwe_barSource();

        
        if (data != null)
        {
            IO.writeLine("" + data.length);
        }
        else
        {
            IO.writeLine("data is null");
        }

    }

    public void good() throws Throwable
    {
        cwe_foo();
        cwe_bar();
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
