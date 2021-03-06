package testcases.testset4;

import testcasesupport.*;

public class testset4_2_09 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        int [] data;
        if (IO.STATIC_FINAL_TRUE)
        {
            
            data = null;
        }
        else
        {
            

            data = null;
        }

        if (IO.STATIC_FINAL_TRUE)
        {
            
            IO.writeLine("" + data.length);
        }
    }

    
    private void cwe_foo1() throws Throwable
    {
        int [] data;
        if (IO.STATIC_FINAL_FALSE)
        {
            

            data = null;
        }
        else
        {

            
            data = new int[5];

        }

        if (IO.STATIC_FINAL_TRUE)
        {
            
            IO.writeLine("" + data.length);
        }
    }

    
    private void cwe_foo2() throws Throwable
    {
        int [] data;
        if (IO.STATIC_FINAL_TRUE)
        {
            
            data = new int[5];
        }
        else
        {
            

            data = null;
        }

        if (IO.STATIC_FINAL_TRUE)
        {
            
            IO.writeLine("" + data.length);
        }
    }

    
    private void cwe_bar1() throws Throwable
    {
        int [] data;
        if (IO.STATIC_FINAL_TRUE)
        {
            
            data = null;
        }
        else
        {
            

            data = null;
        }

        if (IO.STATIC_FINAL_FALSE)
        {
            
            IO.writeLine("Benign, fixed string");
        }
        else
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
    }

    
    private void cwe_bar2() throws Throwable
    {
        int [] data;
        if (IO.STATIC_FINAL_TRUE)
        {
            
            data = null;
        }
        else
        {
            

            data = null;
        }

        if (IO.STATIC_FINAL_TRUE)
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
