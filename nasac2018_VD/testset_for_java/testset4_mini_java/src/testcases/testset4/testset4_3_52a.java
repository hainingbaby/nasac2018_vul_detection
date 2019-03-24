package testcases.testset4;

import testcasesupport.*;

public class testset4_3_52a extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        String data;

        
        data = null;

        (new testset4_3_52b()).foo_barSink(data );
    }

    public void good() throws Throwable
    {
        cwe_foo();
        cwe_bar();
    }

    
    private void cwe_foo() throws Throwable
    {
        String data;

        
        data = "This is not null";

        (new testset4_3_52b()).cwe_fooSink(data );
    }

    
    private void cwe_bar() throws Throwable
    {
        String data;

        
        data = null;

        (new testset4_3_52b()).cwe_barSink(data );
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
