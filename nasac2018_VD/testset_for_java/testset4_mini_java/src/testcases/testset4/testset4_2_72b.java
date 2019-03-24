package testcases.testset4;

import testcasesupport.*;
import java.util.Vector;

public class testset4_2_72b
{
    public void foo_barSink(Vector<int []> dataVector ) throws Throwable
    {
        int [] data = dataVector.remove(2);

        
        IO.writeLine("" + data.length);

    }

    
    public void cwe_fooSink(Vector<int []> dataVector ) throws Throwable
    {
        int [] data = dataVector.remove(2);

        
        IO.writeLine("" + data.length);

    }

    
    public void cwe_barSink(Vector<int []> dataVector ) throws Throwable
    {
        int [] data = dataVector.remove(2);

        
        if (data != null)
        {
            IO.writeLine("" + data.length);
        }
        else
        {
            IO.writeLine("data is null");
        }

    }
}
