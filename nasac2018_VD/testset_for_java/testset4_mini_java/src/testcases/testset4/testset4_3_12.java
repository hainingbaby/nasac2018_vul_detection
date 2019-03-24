package testcases.testset4;

import testcasesupport.*;

public class testset4_3_12 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        String data;
        if(IO.staticReturnsTrueOrFalse())
        {
            
            data = null;
        }
        else
        {

            
            data = "This is not null";

        }

        if(IO.staticReturnsTrueOrFalse())
        {
            
            IO.writeLine("" + data.length());
        }
        else
        {

            
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

    

    private void cwe_foo() throws Throwable
    {
        String data;
        if(IO.staticReturnsTrueOrFalse())
        {
            
            data = "This is not null";
        }
        else
        {

            
            data = "This is not null";

        }

        if(IO.staticReturnsTrueOrFalse())
        {
            
            IO.writeLine("" + data.length());
        }
        else
        {

            
            IO.writeLine("" + data.length());

        }
    }

    

    private void cwe_bar() throws Throwable
    {
        String data;
        if(IO.staticReturnsTrueOrFalse())
        {
            
            data = null;
        }
        else
        {

            
            data = null;

        }

        if(IO.staticReturnsTrueOrFalse())
        {
            
            if (data != null)
            {
                IO.writeLine("" + data.length());
            }
            else
            {
                IO.writeLine("data is null");
            }
        }
        else
        {

            
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

    public void good() throws Throwable
    {
        cwe_foo();
        cwe_bar();
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
