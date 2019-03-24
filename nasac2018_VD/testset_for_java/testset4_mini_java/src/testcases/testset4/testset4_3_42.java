package testcases.testset4;

import testcasesupport.*;

public class testset4_3_42 extends AbstractTestCase
{
    private String foo_barSource() throws Throwable
    {
        String data;

        
        data = null;

        return data;
    }

    public void foo_bar() throws Throwable
    {
        String data = foo_barSource();

        
        IO.writeLine("" + data.length());

    }

    
    private String cwe_fooSource() throws Throwable
    {
        String data;

        
        data = "This is not null";

        return data;
    }

    private void cwe_foo() throws Throwable
    {
        String data = cwe_fooSource();

        
        IO.writeLine("" + data.length());

    }

    
    private String cwe_barSource() throws Throwable
    {
        String data;

        
        data = null;

        return data;
    }

    private void cwe_bar() throws Throwable
    {
        String data = cwe_barSource();

        
        if (data != null)
        {
            IO.writeLine("" + data.length());
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
