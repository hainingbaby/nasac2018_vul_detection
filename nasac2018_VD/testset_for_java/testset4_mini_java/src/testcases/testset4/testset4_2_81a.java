package testcases.testset4;

import testcasesupport.*;

public class testset4_2_81a extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        int [] data;

        
        data = null;

        testset4_2_81_base baseObject = new testset4_2_81_foo_bar();
        baseObject.action(data );
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

        testset4_2_81_base baseObject = new testset4_2_81_cwe_foo();
        baseObject.action(data );
    }

    
    private void cwe_bar() throws Throwable
    {
        int [] data;

        
        data = null;

        testset4_2_81_base baseObject = new testset4_2_81_cwe_bar();
        baseObject.action(data );
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
