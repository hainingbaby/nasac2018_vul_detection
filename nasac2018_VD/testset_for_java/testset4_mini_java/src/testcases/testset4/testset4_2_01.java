package testcases.testset4;

import testcasesupport.*;

public class testset4_2_01 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        int [] data;

        
        data = null;

        
        IO.writeLine("" + data.length);

    }

    public void good() throws Throwable
    {
        cwe_foo();
        cwe_bar();
    }

    
    private void cwe_foo() throws Throwable
    {
        int [] data;

        
        data = new int[5];

        
        IO.writeLine("" + data.length);

    }

    
    private void cwe_bar() throws Throwable
    {
        int [] data;

        
        data = null;

        
        if (data != null)
        {
            IO.writeLine("" + data.length);
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

