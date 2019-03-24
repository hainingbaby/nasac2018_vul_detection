package testcases.testset4;

import testcasesupport.*;

public class testset4_2_17 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        int [] data;
      
        data = null;

        for (int j = 0; j < 1; j++)
        {
            
            IO.writeLine("" + data.length);
        }
    }

    
    private void cwe_foo() throws Throwable
    {
        int [] data;

        
        data = new int[5];

        for (int j = 0; j < 1; j++)
        {
            
            IO.writeLine("" + data.length);
        }
    }

    
    private void cwe_bar() throws Throwable
    {
        int [] data;

        
        data = null;

        for (int k = 0; k < 1; k++)
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
        cwe_foo();
        cwe_bar();
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
