package testcases.testset4;

import testcasesupport.*;
import java.util.LinkedList;

public class testset4_3_73a extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        String data;

        
        data = null;

        LinkedList<String> dataLinkedList = new LinkedList<String>();
        dataLinkedList.add(0, data);
        dataLinkedList.add(1, data);
        dataLinkedList.add(2, data);
        (new testset4_3_73b()).foo_barSink(dataLinkedList  );
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

        LinkedList<String> dataLinkedList = new LinkedList<String>();
        dataLinkedList.add(0, data);
        dataLinkedList.add(1, data);
        dataLinkedList.add(2, data);
        (new testset4_3_73b()).cwe_fooSink(dataLinkedList  );
    }

    
    private void cwe_bar() throws Throwable
    {
        String data;

        
        data = null;

        LinkedList<String> dataLinkedList = new LinkedList<String>();
        dataLinkedList.add(0, data);
        dataLinkedList.add(1, data);
        dataLinkedList.add(2, data);
        (new testset4_3_73b()).cwe_barSink(dataLinkedList  );
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }

}
