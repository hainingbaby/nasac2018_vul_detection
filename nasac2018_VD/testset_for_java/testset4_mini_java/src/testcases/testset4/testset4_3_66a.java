package testcases.testset4;

import testcasesupport.*;

public class testset4_3_66a extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        String data;

        
        data = null;

        String[] dataArray = new String[5];
        dataArray[2] = data;
        (new testset4_3_66b()).foo_barSink(dataArray  );
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

        String[] dataArray = new String[5];
        dataArray[2] = data;
        (new testset4_3_66b()).cwe_fooSink(dataArray  );
    }

    
    private void cwe_bar() throws Throwable
    {
        String data;

        
        data = null;

        String[] dataArray = new String[5];
        dataArray[2] = data;
        (new testset4_3_66b()).cwe_barSink(dataArray  );
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }

}
