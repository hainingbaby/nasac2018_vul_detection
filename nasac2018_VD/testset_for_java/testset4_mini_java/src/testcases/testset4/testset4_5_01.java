package testcases.testset4;

import testcasesupport.*;

public class testset4_5_01 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        Integer data;

        
        data = null;

        
        IO.writeLine("" + data.toString());

    }

    public void good() throws Throwable
    {
        cwe_foo();
        cwe_bar();
    }

    
    private void cwe_foo() throws Throwable
    {
        Integer data;

        
        data = Integer.valueOf(5);

        
        IO.writeLine("" + data.toString());

    }

    
    private void cwe_bar() throws Throwable
    {
        Integer data;

        
        data = null;

        
        if (data != null)
        {
            IO.writeLine("" + data.toString());
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

