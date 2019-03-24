package testcases.testset4;

import testcasesupport.*;
import java.util.Vector;

public class testset4_2_72a extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        int [] data;

        
        data = null;

        Vector<int []> dataVector = new Vector<int []>(5);
        dataVector.add(0, data);
        dataVector.add(1, data);
        dataVector.add(2, data);
        (new testset4_2_72b()).foo_barSink(dataVector  );
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

        Vector<int []> dataVector = new Vector<int []>(5);
        dataVector.add(0, data);
        dataVector.add(1, data);
        dataVector.add(2, data);
        (new testset4_2_72b()).cwe_fooSink(dataVector  );
    }

    
    private void cwe_bar() throws Throwable
    {
        int [] data;

        
        data = null;

        Vector<int []> dataVector = new Vector<int []>(5);
        dataVector.add(0, data);
        dataVector.add(1, data);
        dataVector.add(2, data);
        (new testset4_2_72b()).cwe_barSink(dataVector  );
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }

}
