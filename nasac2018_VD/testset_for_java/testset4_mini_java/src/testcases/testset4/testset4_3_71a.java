package testcases.testset4;

import testcasesupport.*;

public class testset4_3_71a extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        String data;

        
        data = null;

        (new testset4_3_71b()).foo_barSink((Object)data  );
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

        (new testset4_3_71b()).cwe_fooSink((Object)data  );
    }

    
    private void cwe_bar() throws Throwable
    {
        String data;

        
        data = null;

        (new testset4_3_71b()).cwe_barSink((Object)data  );
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
