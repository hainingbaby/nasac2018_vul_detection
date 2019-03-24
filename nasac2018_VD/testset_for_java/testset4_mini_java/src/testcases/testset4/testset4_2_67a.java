package testcases.testset4;

import testcasesupport.*;

public class testset4_2_67a extends AbstractTestCase
{
    static class Container
    {
        public int [] containerOne;
    }

    public void foo_bar() throws Throwable
    {
        int [] data;

        
        data = null;

        Container dataContainer = new Container();
        dataContainer.containerOne = data;
        (new testset4_2_67b()).foo_barSink(dataContainer  );
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

        Container dataContainer = new Container();
        dataContainer.containerOne = data;
        (new testset4_2_67b()).cwe_fooSink(dataContainer  );
    }

    
    private void cwe_bar() throws Throwable
    {
        int [] data;

        
        data = null;

        Container dataContainer = new Container();
        dataContainer.containerOne = data;
        (new testset4_2_67b()).cwe_barSink(dataContainer  );
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }

}
