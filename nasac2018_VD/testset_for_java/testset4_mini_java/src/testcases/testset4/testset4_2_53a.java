package testcases.testset4;

import testcasesupport.*;

public class testset4_2_53a extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        int [] data;

        
        data = null;

        (new testset4_2_53b()).foo_barSink(data );
    }

    public void good() throws Throwable
    {
        cwe_foo();
        cwe_bar();
    }

    
    private void cwe_foo() throws Throwable
    {
        int [] data;

        
        data = new int[5];

        (new testset4_2_53b()).cwe_fooSink(data );
    }

    
    private void cwe_bar() throws Throwable
    {
        int [] data;

        
        data = null;

        (new testset4_2_53b()).cwe_barSink(data );
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }

}
