package testcases.testset4;

import testcasesupport.*;

public class testset4_3_15 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        String data;

        switch (6)
        {
        case 6:
            
            data = null;
            break;
        default:
            

            data = null;
            break;
        }

        switch (7)
        {
        case 7:
            
            IO.writeLine("" + data.length());
            break;
        default:
            
            IO.writeLine("Benign, fixed string");
            break;
        }
    }

    
    private void cwe_foo1() throws Throwable
    {
        String data;

        switch (5)
        {
        case 6:
            

            data = null;
            break;
        default:
            
            data = "This is not null";
            break;
        }

        switch (7)
        {
        case 7:
            
            IO.writeLine("" + data.length());
            break;
        default:
            
            IO.writeLine("Benign, fixed string");
            break;
        }
    }

    
    private void cwe_foo2() throws Throwable
    {
        String data;

        switch (6)
        {
        case 6:
            
            data = "This is not null";
            break;
        default:
            

            data = null;
            break;
        }

        switch (7)
        {
        case 7:
            
            IO.writeLine("" + data.length());
            break;
        default:
            
            IO.writeLine("Benign, fixed string");
            break;
        }
    }

    
    private void cwe_bar1() throws Throwable
    {
        String data;

        switch (6)
        {
        case 6:
            
            data = null;
            break;
        default:
            

            data = null;
            break;
        }

        switch (8)
        {
        case 7:
            
            IO.writeLine("Benign, fixed string");
            break;
        default:
            
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

    
    private void cwe_bar2() throws Throwable
    {
        String data;

        switch (6)
        {
        case 6:
            
            data = null;
            break;
        default:
            

            data = null;
            break;
        }

        switch (7)
        {
        case 7:
            
            if (data != null)
            {
                IO.writeLine("" + data.length());
            }
            else
            {
                IO.writeLine("data is null");
            }
            break;
        default:
            
            IO.writeLine("Benign, fixed string");
            break;
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
