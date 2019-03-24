package testcases.testset4;

import testcasesupport.*;

public class testset4_2_68a extends AbstractTestCase
{
    public static int [] data;

    public void foo_bar() throws Throwable
    {

        
        data = null;

        (new testset4_2_68b()).foo_barSink();
    }

    public void good() throws Throwable
    {
        cwe_foo();
        cwe_bar();
    }

    
    private void cwe_foo() throws Throwable
    {

        
        data = new int[5];

        (new testset4_2_68b()).cwe_fooSink();
    }

    
    private void cwe_bar() throws Throwable
    {

        
        data = null;

        (new testset4_2_68b()).cwe_barSink();
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
