package testcases.testset4;

import testcasesupport.*;
import java.util.HashMap;

public class testset4_3_74a extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        String data;

        
        data = null;

        HashMap<Integer,String> dataHashMap = new HashMap<Integer,String>();
        dataHashMap.put(0, data);
        dataHashMap.put(1, data);
        dataHashMap.put(2, data);
        (new testset4_3_74b()).foo_barSink(dataHashMap  );
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

        HashMap<Integer,String> dataHashMap = new HashMap<Integer,String>();
        dataHashMap.put(0, data);
        dataHashMap.put(1, data);
        dataHashMap.put(2, data);
        (new testset4_3_74b()).cwe_fooSink(dataHashMap  );
    }

    
    private void cwe_bar() throws Throwable
    {
        String data;

        
        data = null;

        HashMap<Integer,String> dataHashMap = new HashMap<Integer,String>();
        dataHashMap.put(0, data);
        dataHashMap.put(1, data);
        dataHashMap.put(2, data);
        (new testset4_3_74b()).cwe_barSink(dataHashMap  );
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
