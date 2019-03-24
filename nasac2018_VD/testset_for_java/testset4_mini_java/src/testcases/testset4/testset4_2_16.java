package testcases.testset4;

import testcasesupport.*;

public class testset4_2_16 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        int [] data;

        while (true)
        {
            
            data = null;
            break;
        }

        while (true)
        {
            
            IO.writeLine("" + data.length);
            break;
        }
    }

    
    private void cwe_foo() throws Throwable
    {
        int [] data;

        while (true)
        {
            
            data = new int[5];
            break;
        }

        while (true)
        {
            
            IO.writeLine("" + data.length);
            break;
        }

    }

    
    private void cwe_bar() throws Throwable
    {
        int [] data;

        while (true)
        {
            
            data = null;
            break;
        }

        while (true)
        {
            
            if (data != null)
            {
                IO.writeLine("" + data.length);
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
