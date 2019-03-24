package testcases.testset4;

import testcasesupport.*;

public class testset4_2_61a extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        int [] data = (new testset4_2_61b()).foo_barSource();

        
        IO.writeLine("" + data.length);

    }

    public void good() throws Throwable
    {
        cwe_foo();
        cwe_bar();
    }

    
    private void cwe_foo() throws Throwable
    {
        int [] data = (new testset4_2_61b()).cwe_fooSource();

        
        IO.writeLine("" + data.length);

    }

    
    private void cwe_bar() throws Throwable
    {
        int [] data = (new testset4_2_61b()).cwe_barSource();

        
        if (data != null)
        {
            IO.writeLine("" + data.length);
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
