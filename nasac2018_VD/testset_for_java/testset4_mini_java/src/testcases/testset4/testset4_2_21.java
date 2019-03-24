package testcases.testset4;

import testcasesupport.*;

public class testset4_2_21 extends AbstractTestCase
{
    
    private boolean foo_barPrivate = false;

    public void foo_bar() throws Throwable
    {
        int [] data;

        
        data = null;

        foo_barPrivate = true;
        foo_barSink(data );
    }

    private void foo_barSink(int [] data ) throws Throwable
    {
        if (foo_barPrivate)
        {
            
            IO.writeLine("" + data.length);
        }
    }

    
    private boolean cwe_bar1Private = false;
    private boolean cwe_bar2Private = false;
    private boolean cwe_fooPrivate = false;

    public void good() throws Throwable
    {
        cwe_bar1();
        cwe_bar2();
        cwe_foo();
    }

    
    private void cwe_bar1() throws Throwable
    {
        int [] data;

        
        data = null;

        cwe_bar1Private = false;
        cwe_bar1Sink(data );
    }

    private void cwe_bar1Sink(int [] data ) throws Throwable
    {
        if (cwe_bar1Private)
        {
            
            IO.writeLine("Benign, fixed string");
        }
        else
        {

            
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

    
    private void cwe_bar2() throws Throwable
    {
        int [] data;

        
        data = null;

        cwe_bar2Private = true;
        cwe_bar2Sink(data );
    }

    private void cwe_bar2Sink(int [] data ) throws Throwable
    {
        if (cwe_bar2Private)
        {
            
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

    
    private void cwe_foo() throws Throwable
    {
        int [] data;

        
        data = new int[5];

        cwe_fooPrivate = true;
        cwe_fooSink(data );
    }

    private void cwe_fooSink(int [] data ) throws Throwable
    {
        if (cwe_fooPrivate)
        {
            
            IO.writeLine("" + data.length);
        }
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
