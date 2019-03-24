package testcases.testset4;

import testcasesupport.*;

public class testset4_4_01 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        StringBuilder data;

        
        data = null;

        
        IO.writeLine("" + data.length());

    }

    public void good() throws Throwable
    {
        cwe_foo();
        cwe_bar();
    }

    
    private void cwe_foo() throws Throwable
    {
        StringBuilder data;

        
        data = new StringBuilder();

        
        IO.writeLine("" + data.length());

    }

    
    private void cwe_bar() throws Throwable
    {
        StringBuilder data;

        
        data = null;

        
        if (data != null)
        {
            IO.writeLine("" + data.length());
        }
        else
        {
            IO.writeLine("data is null");
        }

    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}

