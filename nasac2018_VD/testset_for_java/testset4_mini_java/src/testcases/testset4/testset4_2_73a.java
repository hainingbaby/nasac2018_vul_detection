package testcases.testset4;

import testcasesupport.*;
import java.util.LinkedList;

public class testset4_2_73a extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        int [] data;

        
        data = null;

        LinkedList<int []> dataLinkedList = new LinkedList<int []>();
        dataLinkedList.add(0, data);
        dataLinkedList.add(1, data);
        dataLinkedList.add(2, data);
        (new testset4_2_73b()).foo_barSink(dataLinkedList  );
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

        LinkedList<int []> dataLinkedList = new LinkedList<int []>();
        dataLinkedList.add(0, data);
        dataLinkedList.add(1, data);
        dataLinkedList.add(2, data);
        (new testset4_2_73b()).cwe_fooSink(dataLinkedList  );
    }

    
    private void cwe_bar() throws Throwable
    {
        int [] data;

        
        data = null;

        LinkedList<int []> dataLinkedList = new LinkedList<int []>();
        dataLinkedList.add(0, data);
        dataLinkedList.add(1, data);
        dataLinkedList.add(2, data);
        (new testset4_2_73b()).cwe_barSink(dataLinkedList  );
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }

}
