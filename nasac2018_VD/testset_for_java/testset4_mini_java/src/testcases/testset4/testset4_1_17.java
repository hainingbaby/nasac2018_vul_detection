package testcases.testset4;

import testcasesupport.*;

public class testset4_1_17 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        for(int j = 0; j < 1; j++)
        {
            {
                
                String myString = null;
                if (myString == null)
                {
                    IO.writeLine(myString.length());
                }
            }
        }
    }

    
    private void good1() throws Throwable
    {
        for(int k = 0; k < 1; k++)
        {
            {
                
                String myString = null;
                if (myString == null)
                {
                    IO.writeLine("The string is null");
                }
            }
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
