package testcases.testset4;

import testcasesupport.*;
import java.util.HashMap;

public class testset4_2_74a extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        int [] data;

        
        data = null;

        HashMap<Integer,int []> dataHashMap = new HashMap<Integer,int []>();
        dataHashMap.put(0, data);
        dataHashMap.put(1, data);
        dataHashMap.put(2, data);
        (new testset4_2_74b()).foo_barSink(dataHashMap  );
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

        HashMap<Integer,int []> dataHashMap = new HashMap<Integer,int []>();
        dataHashMap.put(0, data);
        dataHashMap.put(1, data);
        dataHashMap.put(2, data);
        (new testset4_2_74b()).cwe_fooSink(dataHashMap  );
    }

    
    private void cwe_bar() throws Throwable
    {
        int [] data;

        
        data = null;

        HashMap<Integer,int []> dataHashMap = new HashMap<Integer,int []>();
        dataHashMap.put(0, data);
        dataHashMap.put(1, data);
        dataHashMap.put(2, data);
        (new testset4_2_74b()).cwe_barSink(dataHashMap  );
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
