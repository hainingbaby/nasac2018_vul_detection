package testcases.testset4;

import testcasesupport.*;
import java.util.HashMap;

public class testset4_3_74b
{
    public void foo_barSink(HashMap<Integer,String> dataHashMap ) throws Throwable
    {
        String data = dataHashMap.get(2);

        
        IO.writeLine("" + data.length());

    }

    
    public void cwe_fooSink(HashMap<Integer,String> dataHashMap ) throws Throwable
    {
        String data = dataHashMap.get(2);

        
        IO.writeLine("" + data.length());

    }

    
    public void cwe_barSink(HashMap<Integer,String> dataHashMap ) throws Throwable
    {
        String data = dataHashMap.get(2);

        
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
