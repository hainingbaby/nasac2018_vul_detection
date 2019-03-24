package testcases.testset4;

import testcasesupport.*;

public class testset4_1_01 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {

        {
            
            String myString = null;

            if (myString == null)
            {
                IO.writeLine(myString.length());
            }
        }

    }

    public void good() throws Throwable
    {
        good1();
    }

    private void good1() throws Throwable
    {

        {
            
            String myString = null;

            if (myString == null)
            {
                IO.writeLine("The string is null");
            }
        }

    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}

