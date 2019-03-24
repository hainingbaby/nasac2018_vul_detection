package testcases.testset4;

import testcasesupport.*;

public class testset4_3_31 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        String dataCopy;
        {
            String data;

            
            data = null;

            dataCopy = data;
        }
        {
            String data = dataCopy;

            
            IO.writeLine("" + data.length());

        }
    }

    public void good() throws Throwable
    {
        cwe_foo();
        cwe_bar();
    }

    
    private void cwe_foo() throws Throwable
    {
        String dataCopy;
        {
            String data;

            
            data = "This is not null";

            dataCopy = data;
        }
        {
            String data = dataCopy;

            
            IO.writeLine("" + data.length());

        }
    }

    
    private void cwe_bar() throws Throwable
    {
        String dataCopy;
        {
            String data;

            
            data = null;

            dataCopy = data;
        }
        {
            String data = dataCopy;

            
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

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
