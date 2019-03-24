package testcases.testset4;

import testcasesupport.*;

public class testset4_1_16 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        while(true)
        {
            {
                
                String myString = null;
                if (myString == null)
                {
                    IO.writeLine(myString.length());
                }
            }
            break;
        }
    }

    
    private void good1() throws Throwable
    {
        while(true)
        {
            {
                
                String myString = null;
                if (myString == null)
                {
                    IO.writeLine("The string is null");
                }
            }
            break;
        }
    }

    public void good() throws Throwable
    {
        good1();
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
