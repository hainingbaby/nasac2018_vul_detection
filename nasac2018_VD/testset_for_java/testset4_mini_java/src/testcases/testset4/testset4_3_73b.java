package testcases.testset4;

import testcasesupport.*;
import java.util.LinkedList;

public class testset4_3_73b
{
    public void foo_barSink(LinkedList<String> dataLinkedList ) throws Throwable
    {
        String data = dataLinkedList.remove(2);

        
        IO.writeLine("" + data.length());

    }

    
    public void cwe_fooSink(LinkedList<String> dataLinkedList ) throws Throwable
    {
        String data = dataLinkedList.remove(2);

        
        IO.writeLine("" + data.length());

    }

    
    public void cwe_barSink(LinkedList<String> dataLinkedList ) throws Throwable
    {
        String data = dataLinkedList.remove(2);

        
        if (data != null)
        {
            IO.writeLine("" + data.length());
        }
        else
        {
            IO.writeLine("data is null");
        }

    }
}
