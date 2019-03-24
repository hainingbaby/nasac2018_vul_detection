package testcases.testset4;

import testcasesupport.*;

public class testset4_2_31 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        int [] dataCopy;
        {
            int [] data;

            
            data = null;

            dataCopy = data;
        }
        {
            int [] data = dataCopy;

            
            IO.writeLine("" + data.length);

        }
    }

    public void good() throws Throwable
    {
        cwe_foo();
        cwe_bar();
    }

    
    private void cwe_foo() throws Throwable
    {
        int [] dataCopy;
        {
            int [] data;

            
            data = new int[5];

            dataCopy = data;
        }
        {
            int [] data = dataCopy;

            
            IO.writeLine("" + data.length);

        }
    }

    
    private void cwe_bar() throws Throwable
    {
        int [] dataCopy;
        {
            int [] data;

            
            data = null;

            dataCopy = data;
        }
        {
            int [] data = dataCopy;

            
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

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
