package testcases.testset4;

import testcasesupport.*;

public class testset4_3_81a extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        String data;

        
        data = null;

        testset4_3_81_base baseObject = new testset4_3_81_foo_bar();
        baseObject.action(data );
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

        testset4_3_81_base baseObject = new testset4_3_81_cwe_foo();
        baseObject.action(data );
    }

    
    private void cwe_bar() throws Throwable
    {
        String data;

        
        data = null;

        testset4_3_81_base baseObject = new testset4_3_81_cwe_bar();
        baseObject.action(data );
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
