package testcases.testset4;

import testcasesupport.*;

public class testset4_3_22a extends AbstractTestCase
{
    

    public static boolean foo_barPublicStatic = false;

    public void foo_bar() throws Throwable
    {
        String data = null;

        
        data = null;

        foo_barPublicStatic = true;
        (new testset4_3_22b()).foo_barSink(data );
    }

    

    public static boolean cwe_bar1PublicStatic = false;
    public static boolean cwe_bar2PublicStatic = false;
    public static boolean cwe_fooPublicStatic = false;

    public void good() throws Throwable
    {
        cwe_bar1();
        cwe_bar2();
        cwe_foo();
    }

    
    private void cwe_bar1() throws Throwable
    {
        String data = null;

        
        data = null;

        cwe_bar1PublicStatic = false;
        (new testset4_3_22b()).cwe_bar1Sink(data );
    }

    
    private void cwe_bar2() throws Throwable
    {
        String data = null;

        
        data = null;

        cwe_bar2PublicStatic = true;
        (new testset4_3_22b()).cwe_bar2Sink(data );
    }

    
    private void cwe_foo() throws Throwable
    {
        String data = null;

        
        data = "This is not null";

        cwe_fooPublicStatic = true;
        (new testset4_3_22b()).cwe_fooSink(data );
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
