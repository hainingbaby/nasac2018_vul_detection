package testcases.testset4;

import testcasesupport.*;

public class testset4_3_02 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        String data;
        if (true)
        {
            
            data = null;
        }
        else
        {
            

            data = null;
        }

        if (true)
        {
            
            IO.writeLine("" + data.length());
        }
    }

    
    private void cwe_foo1() throws Throwable
    {
        String data;
        if (false)
        {
            

            data = null;
        }
        else
        {

            
            data = "This is not null";

        }

        if (true)
        {
            
            IO.writeLine("" + data.length());
        }
    }

    
    private void cwe_foo2() throws Throwable
    {
        String data;
        if (true)
        {
            
            data = "This is not null";
        }
        else
        {
            

            data = null;
        }

        if (true)
        {
            
            IO.writeLine("" + data.length());
        }
    }

    
    private void cwe_bar1() throws Throwable
    {
        String data;
        if (true)
        {
            
            data = null;
        }
        else
        {
            

            data = null;
        }

        if (false)
        {
            
            IO.writeLine("Benign, fixed string");
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

    
    private void cwe_bar2() throws Throwable
    {
        String data;
        if (true)
        {
            
            data = null;
        }
        else
        {
            

            data = null;
        }

        if (true)
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

    public void good() throws Throwable
    {
        cwe_foo1();
        cwe_foo2();
        cwe_bar1();
        cwe_bar2();
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
