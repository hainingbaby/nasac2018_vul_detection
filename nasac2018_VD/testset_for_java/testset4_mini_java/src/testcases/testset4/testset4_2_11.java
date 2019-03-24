package testcases.testset4;

import testcasesupport.*;

public class testset4_2_11 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        int [] data;
        if (IO.staticReturnsTrue())
        {
            
            data = null;
        }
        else
        {
            

            data = null;
        }

        if(IO.staticReturnsTrue())
        {
            
            IO.writeLine("" + data.length);
        }
    }

    
    private void cwe_foo1() throws Throwable
    {
        int [] data;
        if (IO.staticReturnsFalse())
        {
            

            data = null;
        }
        else
        {

            
            data = new int[5];

        }

        if (IO.staticReturnsTrue())
        {
            
            IO.writeLine("" + data.length);
        }
    }

    
    private void cwe_foo2() throws Throwable
    {
        int [] data;

        if (IO.staticReturnsTrue())
        {
            
            data = new int[5];
        }
        else
        {
            

            data = null;
        }

        if (IO.staticReturnsTrue())
        {
            
            IO.writeLine("" + data.length);
        }
    }

    
    private void cwe_bar1() throws Throwable
    {
        int [] data;
        if (IO.staticReturnsTrue())
        {
            
            data = null;
        }
        else
        {
            

            data = null;
        }

        if (IO.staticReturnsFalse())
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
        if (IO.staticReturnsTrue())
        {
            
            data = null;
        }
        else
        {
            

            data = null;
        }

        if (IO.staticReturnsTrue())
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
