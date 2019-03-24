package testcases.testset4;

import testcasesupport.*;

public class testset4_3_16 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        String data;

        while (true)
        {
            
            data = null;
            break;
        }

        while (true)
        {
            
            IO.writeLine("" + data.length());
            break;
        }
    }

    
    private void cwe_foo() throws Throwable
    {
        String data;

        while (true)
        {
            
            data = "This is not null";
            break;
        }

        while (true)
        {
            
            IO.writeLine("" + data.length());
            break;
        }

    }

    
    private void cwe_bar() throws Throwable
    {
        String data;

        while (true)
        {
            
            data = null;
            break;
        }

        while (true)
        {
            
            if (data != null)
            {
                IO.writeLine("" + data.length());
            }
            else
            {
                IO.writeLine("data is null");
            }
            break;
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
